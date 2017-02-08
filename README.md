
## dotnet core setup

1. Install dotnetcore for ubuntu
2. install yeoman dotnet core templates
3. Modify the project.json file to allow unsafe code
```
"buildOptions": {
    "emitEntryPoint": true,
    "preserveCompilationContext": true,
    "allowUnsafe": true
  },
```
4. Create an Interop.cs file and class
5. Include the following references [link](https://github.com/dotnet/corefx/blob/79d44f202e4b6d000ca6c6885a24549a55db38f1/src/System.Console/src/Interop/Interop.manual.Unix.cs)

```
using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
```
6. Create a DLLImport Static Method
7. Marshall result from IntPtr to AnsiString
8. Integrate and call it


## Installing STE
Installing STE following the normal instructions documented in the STE getting started PDF
1. extracted files in: 
```
$HOME/ste
        /ste-interface-files
        /ste-root
        /ste-shared-libraries
 ```
 2. copied ste-license.dat to ste-root
 3. created env variable `$ export LD_LIBRARY_PATH=/home/leo/ste/ste-shared-libraries`


## Integrate STE to dotnet
1. linked libste.so to /lib `ln -s $HOME/ste/ste-shared-libraries/libste.so /lib`
2. Copied liblua51.so tp /lib `ln -s $HOME/ste/ste-shared-libraries/liblua51.so /lib`
3. ran ldconfig
4. verify ldcondif --print | grep ste


   