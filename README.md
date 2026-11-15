# Computer Graphics – Practical Assignment 1

Interactive 2D graphics application developed using C++, OpenGL, GLU, and FreeGLUT.

## Run EXE file

1. Open https://github.com/ilyushqqa/CG_Practical_Assignment_1/releases/tag/v1
2. Download and extract CG_Practical_1.zip
3. Run `CG_Practical_1.exe`.

## To Build and Run
**Instructions:**
**Requirements: Visual Studio 22 with Desktop development with C++"**
1. Download or clone the repo.
2. Open `CG_Practical_1.slnx` in Visual Studio.
3. In Project properties -> Configuration Properties -> vcpkg, set "Use vcpkg Manifest" field to **Yes**
4. Select the **x64** platform.
5. Build solution.
6. Run `Ctrl + F5`.

FreeGLUT dependencies are specified in `vcpkg.json` and restored automatically when vcpkg manifest integration is enabled.

## vcpkg install (If Required)

1. Open **Visual Studio Installer → Modify → Individual components** and install **vcpkg package manager**.
2. In Visual Studio, open **Developer PowerShell** terminal and run:

```powershell
vcpkg integrate install
```

3. Esnure **Use vcpkg Manifest** is set to Yes (Project properties)
4. Build the solution again.
