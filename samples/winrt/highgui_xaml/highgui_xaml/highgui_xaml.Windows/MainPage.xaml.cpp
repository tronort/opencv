﻿//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

#include "video.h"

#include "../../../modules/highgui/src/cap_winrt_highgui.hpp"

using namespace highgui_xaml;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

#include <ppl.h>
#include <ppltasks.h>
#include <concrt.h>
#include <agile.h>

using namespace ::concurrency;
using namespace ::Windows::Foundation;


MainPage::MainPage()
{
    InitializeComponent();

    Video::get().m_cvImage = cvImage;

    // Video::get().initGrabber(0, 640, 480);

    auto asyncTask = TaskWithProgressAsync();
    asyncTask->Progress = ref new AsyncActionProgressHandler<int>([](IAsyncActionWithProgress<int>^ act, int progress)
    {
        int action = progress;

        // these actions will be processed on the UI thread asynchronously
        switch (action)
        {
        case HighguiBridge_OPEN_CAMERA:
            {
                int device = HighguiBridge::get().deviceIndex;
                int width = HighguiBridge::get().width;
                int height = HighguiBridge::get().height;
                Video::get().initGrabber(device, width, height);
            }
            break;
        case HighguiBridge_CLOSE_CAMERA:
            // closeDevice();
            break;
        case HighguiBridge_UPDATE_IMAGE_ELEMENT:
            Video::get().m_cvImage->Source = HighguiBridge::get().m_frontOutputBuffer;
            break;
        }
    });

}

// implemented in main.cpp
void cvMain();

// set the reporter method for the HighguiAssist singleton
// start the main OpenCV as an async thread in WinRT
IAsyncActionWithProgress<int>^ MainPage::TaskWithProgressAsync()
{
    return create_async([this](progress_reporter<int> reporter)
    {
        HighguiBridge::get().setReporter(reporter);
        cvMain();
    });
}

#if 0
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
    (void)e;	// Unused parameter
}
#endif