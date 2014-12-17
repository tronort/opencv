### OpenCV: Open Source Computer Vision Library

####How to build OpenCV for Windows Phone 8.1/8.0/Windows Store
1. open the binWP8_1 folder or another folder depending on your target platform (WinRT, WP8_1)
2. build the opencv.sln using VS2013

####How to setup CMake GUI to build the WindowsPhone and WindowsStore Projects

CMake 3.1 [can now create](http://blogs.msdn.com/b/uk_faculty_connection/archive/2014/07/29/cmake-for-windows-store-and-windows-phone-apps.aspx) Windows Store and Windows Phone project files directly. The following few steps are now required to build OpenCV for these platforms:

* Set up CMake with the correct parameters
* Configure, Generate and Build projects

#####1. Open [CMake GUI](http://www.cmake.org/download/)

#####2. Set the build paths
* Where is the source code: path to opencv
* Where to build the binaries: path to ```opencv/<your-custom-folder>```, usually ```opencv/bin```

#####3. BEFORE going to "Configure" use "Add Entry" button to add the following parameters:
Note that a single platform can be configured at a time. To build for different platform go through these steps and set values for another platform at this step.
- WinowsPhone
 - ```CMAKE_SYSTEM_NAME``` - ```WindowsPhone```
 - ```CMAKE_SYSTEM_VERSION``` - ```8.1``` or ```8.0```
- Winows Store
 - ```CMAKE_SYSTEM_NAME``` - ```WindowsStore```
 - ```CMAKE_SYSTEM_VERSION``` - ```8.1```

#####4. Select ONLY the following Options

* BUILD_JASPER
* BUILD_JPEG
* BUILD_PNG
* BUILD_SHARED_LIBS
* BUILD_TIFF
* BUILD_WITH_DEBUG_INFO
* BUILD_WITH_STATIC_CRT
* BUILD_ZLIB
* BUILD_opencv_calib3d
* BUILD_opencv_core
* BUILD_opencv_features2d
* BUILD_opencv_flann
* BUILD_opencv_imgproc
* BUILD_opencv_ml
* BUILD_opencv_objdetect
* BUILD_opencv_photo
* BUILD_opencv_shape
* BUILD_opencv_stitching
* BUILD_opencv_video
* BUILD_opencv_videostab
* ENABLE_PRECOMPILED_HEADERS
* ENABLE_SOLUTION_FOLDERS
* WITH_JASPER
* WITH_JPEG
* WITH_PNG
* WITH_TIFF
* WITH_VFW

#####5. Click on "Configure"
#####6. Click on "Generate"

This will generate all of the files needed to build open_cv projects for selected platform in ```opencv\bin```. Open the ```opencv\bin``` directory and open the ```OpenCV.sln```. Build all of the projects. They should build without errors.

####Troubleshooting

 - **Problem:** Linker error when building solution<br>
Example: ```error LNK1104: cannot open file '..\..\lib\Debug\opencv_flann300d.lib'	...\binWP8\modules\features2d\LINK opencv_features2d```<br>
**Solutions:** 	
   1. Go to projects’ respective ```bin*``` folders (e.g. in ```WP8_1\modules\core\```) and delete ```*.dir``` folder (e.g. ```opencv_core.dir```).<br>
   2. Build only the selected project (issue source) from Visual Studio, then build the solution.
**Note:** You can also find this problem noted in the log, although the displayed error doesn’t point to it.

<br>

 - **Problem:** Unresolved externals when building solution<br>
**Solution:** 	Go to ```Project Properties -> Linker -> … ``` and set

  1. Ignore import library - **No**
  1. Link Library Dependencies – **Yes**

 for all OCV projects you depend on within current solution.<br> 
 **Note:** This change persists but gets overwritten if OCV projects are regenerated with CMake.

#### Resources

* Homepage: <http://opencv.org>
* Docs: <http://docs.opencv.org>
* Q&A forum: <http://answers.opencv.org>
* Issue tracking: <http://code.opencv.org>

#### Contributing

Please read before starting work on a pull request: <http://code.opencv.org/projects/opencv/wiki/How_to_contribute>

Summary of guidelines:

* One pull request per issue;
* Choose the right base branch;
* Include tests and documentation;
* Clean up "oops" commits before submitting;
* Follow the coding style guide.

[![Donate OpenCV project](http://opencv.org/wp-content/uploads/2013/07/gittip1.png)](https://www.gittip.com/OpenCV/)
[![Donate OpenCV project](http://opencv.org/wp-content/uploads/2013/07/paypal-donate-button.png)](https://www.paypal.com/cgi-bin/webscr?item_name=Donation+to+OpenCV&cmd=_donations&business=accountant%40opencv.org)
