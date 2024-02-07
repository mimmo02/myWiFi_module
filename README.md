
# myWiFi_module

Generic WiFi pcb based on ESP12E module, with 6 output and 3 input.
Appropriate to develope IoT application.


## Authors

- [@Domenico Aquilino](https://github.com/mimmo02)


## Hardware

The IO are customizable, in this case the configuration is made such as there are 6 output and 3 input.

![alt text](https://github.com/mimmo02/myWiFi_module/blob/main/Layout.png?raw=true)

#### Mounted components:



| Component | Type     | Module ESP12E |
| :-------- | :------- | :------------------------- |
| `R6 & R13` | input | `GPIO16` |
| `R7 & R14` | input | `GPIO14` |
| `R8 & R15` | input | `GPIO12` |
| `Q4` | output | `GPIO13` |
| `Q5` | output | `GPIO15` |
| `Q6` | output | `GPIO02` |
| `Q7` | output | `GPIO00` |
| `Q8` | output | `GPIO04` |
| `Q9` | output | `GPIO05` |

#### PCB PIN:

alimentation jumper
| Connector | Pin     | Description |
| :-------- | :------ | :---------- |
| **JP1** | `1-4` | 24V |
| **JP1** | `2-5` | 5V |
| **JP1** | `3-6` | 3.3V |

alimentation connector
| Connector | Pin     | Description |
| :-------- | :------ | :---------- |
| **X1** | `1` | GND |
| **X1** | `2` | +24V |
| **X1** | `3` | +5V |
| **X1** | `4` | +3.3V |

programmation connector
| Connector | Pin     | Description |
| :-------- | :------ | :---------- |
| **X3** | `1` | Rx |
| **X3** | `2` | Tx |
| **X3** | `3` | GND |

GPIO connector
| Connector | Pin     | ESP12E |  esp8266 |
| :-------- | :------ | :---------- | :-----|
| **X2** | `1` | GND | GND |
| **X2** | `2` | GPIO16 | GPIO16 |
| **X2** | `3` | GPIO14 | GPIO14 |
| **X2** | `4` | GPIO12 | GPIO12 |
| **X2** | `5` | GPIO13 | GPIO13 |
| **X2** | `6` | GPIO15 | GPIO15 |
| **X2** | `7` | GPIO02 | GPIO02 |
| **X2** | `8` | GPIO00 | GPIO00 |
| **X2** | `9` | GPIO04 | GPIO04 |
| **X2** | `10` | GPIO05 | GPIO05 |
| **X2** | `11` | ADC | ADC |

