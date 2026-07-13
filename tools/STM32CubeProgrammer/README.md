# STM32CubeProgrammer

STM32CubeProgrammer is the official STMicroelectronics programming tool for STM32 devices. The STM32 Arduino Core can use its command-line interface when uploading firmware.

## Official download

Download STM32CubeProgrammer from the official STMicroelectronics page:

[Download STM32CubeProgrammer from STMicroelectronics](https://www.st.com/en/development-tools/stm32cubeprog.html)

On the ST page, select **Get Software**, choose the Windows package, and follow the download instructions shown by ST.

## Windows installation

1. Download the Windows installer/package from the official link above.
2. Extract the downloaded archive first if it is supplied as a ZIP file.
3. Run the STM32CubeProgrammer installer.
4. Accept the license agreement and keep the normal/default installation location.
5. Complete the installation.
6. Close and reopen Arduino IDE after installation.

A typical default Windows installation folder is:

```text
C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer
```

The command-line executable required by the STM32 Arduino Core is normally located at:

```text
C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe
```

The exact folder may differ if a custom installation location was selected.

## Verify the installation

Open PowerShell and run:

```powershell
Test-Path "C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe"
```

A result of `True` means the CLI executable was found at that location.

## Arduino IDE upload setup

1. Open Arduino IDE.
2. Select the correct STM32 board under **Tools > Board**.
3. Select the correct upload method under **Tools > Upload method**.
4. For an ST-LINK connection, select the available STM32CubeProgrammer SWD upload option.
5. Connect the programmer and click **Upload**.

The exact menu wording can vary depending on the selected STM32 board and STM32 Arduino Core version.

## Fix: STM32CubeProgrammer not found

If Arduino IDE reports:

```text
STM32CubeProgrammer not found (STM32_Programmer_CLI.exe)
```

Add this folder to the Windows `Path` environment variable:

```text
C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin
```

### Add the folder to Windows Path

1. Search Windows for **Edit the system environment variables**.
2. Open **Environment Variables**.
3. Under either User variables or System variables, select **Path**.
4. Click **Edit**.
5. Click **New**.
6. Paste the STM32CubeProgrammer `bin` folder path.
7. Click **OK** on all windows.
8. Restart Arduino IDE.

## Repository note

The STM32CubeProgrammer installer is not stored in this repository because it is a large third-party binary. Download the current installer directly from STMicroelectronics using the official link above.