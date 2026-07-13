# Paano Ikonekta ang FTDI sa STM32 Blue Pill

Kung gusto mo ng **Serial Monitor** sa STM32 Blue Pill, o gusto mong mag-upload gamit ang **UART bootloader**, ito ang basic at safe na setup.

## Wiring picture

![FTDI to STM32 Blue Pill wiring](ftdi_stm32_wiring.svg)

## Basic connection

Gagamitin natin ang **USART1** ng STM32 Blue Pill.

| FTDI | STM32 Blue Pill |
|---|---|
| TX | PA10 (RX1) |
| RX | PA9 (TX1) |
| GND | GND |

### Tandaan

Cross connection ito:

```text
FTDI TX  -> STM32 RX / PA10
FTDI RX  -> STM32 TX / PA9
FTDI GND -> STM32 GND
```

Hindi **TX to TX** at hindi rin **RX to RX**.

## Important bago ikabit

- I-set ang FTDI sa **3.3V logic** para safe sa STM32.
- Kung powered na ang STM32 gamit ang **USB**, **ST-LINK**, o regulated external supply, huwag mo nang ikabit ang VCC ng FTDI.
- Para sa serial communication, ito lang muna ang kailangan:

```text
TX
RX
GND
```

## Para sa Serial Monitor / debugging

Ito ang normal setup kung gusto mo lang mag-print ng readings at debug messages:

```text
FTDI TX  -> PA10
FTDI RX  -> PA9
FTDI GND -> GND
BOOT0    -> 0
```

### Sample code

```cpp
void setup() {
  Serial1.begin(115200);
}

void loop() {
  Serial1.println("Hello from STM32");
  delay(1000);
}
```

Sa Arduino IDE Serial Monitor, itapat sa:

```text
115200 baud
```

## Para sa upload gamit ang FTDI

Kapag UART upload ang gagamitin natin:

### Wiring

```text
FTDI TX  -> PA10
FTDI RX  -> PA9
FTDI GND -> GND
```

### Boot setting

Bago mag-upload:

```text
BOOT0 = 1
```

Pagkatapos:

1. Ilagay ang **BOOT0 sa 1**.
2. Pindutin ang **RESET** ng STM32.
3. Sa Arduino IDE, piliin ang tamang STM32 board.
4. Piliin ang serial/UART upload method na available para sa board.
5. Piliin ang tamang COM port ng FTDI.
6. Click **Upload**.

Kapag successful na ang upload:

1. Ibalik ang **BOOT0 sa 0**.
2. Pindutin ulit ang **RESET**.
3. Tatakbo na ang program natin.

## Kapag walang lumalabas sa Serial Monitor

Check muna ito:

- tama ba ang COM port
- pareho ba ang baud rate
- crossed ba ang TX at RX
- common ba ang GND
- `Serial1` ba ang gamit sa code
- naka-3.3V logic ba ang FTDI

## Kapag upload failed

Check muna ito:

- naka-**BOOT0 = 1** ba bago mag-upload
- na-reset ba ang board
- tama ba ang COM port
- tama ba ang upload method
- may ibang app bang gumagamit ng COM port
- maayos ba ang TX, RX, at GND wiring

## Mabilis na summary

Kung Serial Monitor/debug lang:

```text
BOOT0 = 0
FTDI TX  -> PA10
FTDI RX  -> PA9
FTDI GND -> GND
```

Kung upload gamit ang UART bootloader:

```text
BOOT0 = 1
RESET
UPLOAD

pagkatapos:
BOOT0 = 0
RESET ulit
```

## Tip

Kapag ayaw gumana, ito agad ang unang tingnan natin:

- baliktad ba ang TX at RX
- common ba ang GND
- tama ba ang COM port at baud rate
- naka-3.3V ba ang FTDI

Simple lang ang setup, pero dito madalas nanggagaling ang problema kapag walang serial output o ayaw mag-upload.