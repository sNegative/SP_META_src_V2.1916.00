@set VERSION=2011.09.28
@set BASEDIR=E:\tmp
@set RELEASE_LOCATION="\\glbfs14\sw_releases\Wireless_Global_Tools\Tool_Release\SP META Tool\temp_for_wb_dualmic"
@set WINRAR="C:\Program Files\WinRAR\Rar.exe"


@set DESTDIR=%BASEDIR%\%VERSION%
@set PACKAGE=%BASEDIR%\%VERSION%.rar

rmdir /S /Q %DESTDIR%
mkdir %DESTDIR%

copy *.dll %DESTDIR%
copy *.exe %DESTDIR%
copy *.ini %DESTDIR%
copy *.xml %DESTDIR%
copy *.wav %DESTDIR%

copy Rx_FIR %DESTDIR%
copy Tx_FIR %DESTDIR%
copy MF_setup.txt %DESTDIR%


del /S %PACKAGE%

%WINRAR% a -ep1 %PACKAGE% %DESTDIR%

xcopy %PACKAGE% %RELEASE_LOCATION%  /Y /Z


echo "release done."
start %BASEDIR%
pause
