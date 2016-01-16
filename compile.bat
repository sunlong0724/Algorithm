@echo on

@set option_ctrl=%1

@if [%option_ctrl%]==[-not] goto do_not_cmake

:set_msvc:
	@call "D:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\amd64\vcvars64.bat"
	@if [%option_ctrl%]==[-f] goto do_cmake 
	@if [%option_ctrl%]==[-g] goto gen_sln 

:do_cmake
	@if exist output rd /s /q output
	@mkdir output
	@if exist build rd /s /q build
	@ rem call "D:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\amd64\vcvars64.bat"
	
	@mkdir build
	@cd build
	@cmake --build-64bit -G"NMake Makefiles" ..
	@goto do_nmake

:gen_sln:
	@if exist sln rd /s /q sln
	@mkdir sln
	@if not exist output mkdir output

	@call "D:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\amd64\vcvars64.bat"
	@cd sln
	@cmake -G"Visual Studio 14 2015 Win64" ..
	@cd ..
	@goto do_cmake

:do_not_cmake:
	@cd build
	@goto do_nmake

:do_nmake
	@dir
	@nmake && nmake install
	@goto exit

:exit
	@cd ..