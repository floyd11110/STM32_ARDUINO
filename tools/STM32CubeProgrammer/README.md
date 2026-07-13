# STM32CubeProgrammer

STM32CubeProgrammer is used by the STM32 Arduino Core when uploading firmware to supported STM32 boards.

## Typical Windows installation path

```text
C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer
```

Required command-line executable:

```text
C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe
```

## PATH setup

If Arduino IDE cannot find STM32CubeProgrammer, add this folder to the Windows `PATH` environment variable:

```text
C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin
```

The actual installation folder may differ if a custom location was selected during installation.

## Installer file

The STM32CubeProgrammer installer or ZIP is not included in this repository. Upload the installer manually only if redistribution is permitted by its license. Otherwise, download it from the official STMicroelectronics website.
