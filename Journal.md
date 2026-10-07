---
title: "Mini hand vacum+fan "
github: "https://github.com/Chronos-03/HandFanv1"
description: "making bldc based custom battery pack bldc jet fan use as mini vacumm for the cleaning also use as hand fan "
created_at: "2026-09-25"
total_time: "7h 6m"
---

# September 26, 2026: Component Research
<!-- fabricate:entry 6 -->

SO here i just do some research work like first i make the list of the item which i needed for the project so first i make the list of the item which i needed and use AI to find out the best and the cheapest hardware for this project.
I also take care of the miscellaneous item like wire , solder wire , flux too and while finding the best hardware but cheap too as prices wary on different website so , and I try to keep my budget under 50 dollar or else it not gonna be worth project if this crosses the limit of the 50 dollar.

![](https://fabricate.hackclub-assets.com/b538e3ed672a16f909306abf9ac1e36cb3e74ca46b1a4b5f60c638629bd783fa/Screenshot%202026-09-26%20at%203.31.04%E2%80%AFAM.png)

**Total time spent: 48m**

# September 26, 2026 (entry 2): SCHEMATICS
<!-- fabricate:entry 8 -->

In this session i have find the symbol of the component i wanted to use so the list of the component are

1- 4x 1850 Cells
2- 30A ESC
3- BLDC motor
4- PWM Controller 
5- 4S BMS(Battery management system)
6- Type-c Charging module 
7- Power switch 
After finding the symbol for those project i have done the connection and recheck them and run test to verify the circuit  wether its working or not then complete the schematics file and have the overall view of the project  electrical component and system.

![](https://fabricate.hackclub-assets.com/6532fe5e1aa3e99c18d4fe4633132924ef6d3e7384c02e0e9d9a615b2db95a94/Screenshot%202026-09-26%20at%2011.13.02%E2%80%AFAM.png)

**Total time spent: 1h**

# September 26, 2026 (entry 3): 7-Blade Impeller CAD Design
<!-- fabricate:entry 9 -->

So in this session i have research a little bit about the impeller so get to know that odd number fan or wing impeller are good for this kind of the project so i choose the 7 number for the better air flow.
The primary engineering challenge during this phase was optimizing the blade geometry to strike the perfect balance between static pressure generation and overall air volume displacement. I focused on a swept, curved blade profile that actively channels and compresses the air as it accelerates outward. This specific 7-blade configuration ensures consistent, smooth airflow at high RPMs while maximizing the efficiency of the motor within the tight tolerances of the planned 30mm enclosure.

![](https://fabricate.hackclub-assets.com/0d827d67d1e88394b67cb735a01ebe81d2c112e13d45b961dddc97de41625bda/Screenshot%202026-09-26%20at%201.20.19%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/c93d0a5ea4276f8c64a60fa224053667757f4d3ad1d76393bf1c193bbe10633b/Screenshot%202026-09-26%20at%201.20.27%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/e01aad90c80b9489e00cc7117349189c3f2b016b8ef9c4f51686d330f311d3c9/Screenshot%202026-09-26%20at%201.20.34%E2%80%AFPM.png)

**Total time spent: 1h 6m**

# September 26, 2026 (entry 4): Main Body Enclosure
<!-- fabricate:entry 10 -->

In this session, I focused on designing the primary structural housing for the impeller rig. The goal was to create a unified main body capable of securely mounting the motor assembly. As in previous part the engine was read all was left to do is making body so i choose the body with cylinderical  bldc mount as if i want in future to add some nozzle or attach i can do so .
The CAD process required significant troubleshooting. Attempting to seamlessly integrate the bulky Li-ion cells, the 30A ESC, and the PWM controller into a compact, hand-held form factor resulted in multiple interference and geometric errors in Fusion 360. I spent the majority of the hour resolving these spatial conflicts, adjusting wall thicknesses, and fixing overlapping body warnings to ensure the final STL file would be fully optimized and structurally sound for 3D printing.

![](https://fabricate.hackclub-assets.com/d5b39c51f8cbc9fd4690b1d1031b9a423477ceb646051ef17843212a1665afab/Screenshot%202026-09-26%20at%203.09.53%E2%80%AFPM.png)

**Total time spent: 1h**

# September 26, 2026 (entry 5): Interface Cutouts & Ergonomic Handle Design
<!-- fabricate:entry 12 -->

In this session, I finalized the CAD for the main body by focusing on component integration, wire routing, and user ergonomics. I designed precise cutouts and extrusions along the housing to securely mount the external interface components: the power switches, the PWM speed controller dial, and the Type-C USB charging module.   To ensure clean and safe cable management, I engineered a dedicated routing hole connecting the motor housing to the main electronics compartment, allowing the brushless motor wires to pass through without getting pinched or obstructing airflow. Finally, I focused on the physical feel of the device; because this turbo fan will generate noticeable thrust, I heavily filleted and rounded the handle profile to ensure a secure, comfortable ergonomic grip during handheld operation.
![](https://fabricate.hackclub-assets.com/55c9e43e75eb996fa48fcf156daf3b5adb38926378270f1510d44494970e223d/Screenshot%202026-09-26%20at%2010.23.11%E2%80%AFPM.png)

**Total time spent: 1h 30m**

# September 28, 2026: CAD Refinement & Microcontroller Pivot
<!-- fabricate:entry 31 -->

During this session, I heavily refined the main 3D body, polishing the external features while precisely mapping the internal compartments to house the entire power plant: the four 18650 Li-ion batteries, the BMS, and the Type-C charging module.  

A major engineering pivot occurred regarding the electronics. I realized that using an off-the-shelf PWM speed controller module would be too bulky for the ergonomic handle. Since I am strictly avoiding custom PCB fabrication to cut costs and adhere to the grant budget, I cannot solder raw SMD chips. Instead, I swapped the bulky controller for a Digispark ATtiny85 development board paired with a simple rotary potentiometer. This allows me to write custom firmware to generate the ESC signal, maintaining a highly compact, point-to-point wiring architecture that easily fits inside the refined CAD model.

![](https://fabricate.hackclub-assets.com/8fda266f425a788828e9e03741c3c7a271727b9055500ddeae291c20ff9e4df8/Screenshot%202026-09-28%20at%202.40.36%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/14b5200b530a977cd2252cc71d139907b1382b255c93a41678be05c273b4732e/Screenshot%202026-09-28%20at%203.09.33%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/13e9c262111f761e32c6e95c2992adac10b9d08eeb0ead0989ab864234b3193c/Screenshot%202026-09-28%20at%203.09.42%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/ca3fae30e299779e28427423429a471dc3cd714303cb84f62b0712bc0e1359ed/Screenshot%202026-09-28%20at%203.10.03%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/3dfdb49b13d92192450d89e49f6dce0f01cebc075a84845d16e7ac3df2026fbb/Screenshot%202026-09-28%20at%203.10.10%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/214be5573fd5e8a9e044bb3f927eef90b4fd38f4fb99875d2cb7410bdcd19780/Screenshot%202026-09-28%20at%203.10.24%E2%80%AFPM.png)

Timelapse: https://lapse.hackclub.com/timelapse/Eumulaynib4_

**Total time spent: 1h**

# September 28, 2026 (entry 2): Final Assembly CAD & Ergonomic Details
<!-- fabricate:entry 33 -->

In this final design session, I completed the full CAD assembly of the impeller rig. My main objective was arranging the remaining internal components into their designated compartments.   I also heavily refined the external housing. To make the handheld fan comfortable to hold, I applied rounded corners across the profile. Additionally, I carved out precise mounting grooves for the external interface, specifically tailoring the cutouts to flush-mount the Type-C charging module, the power button, and the rotary speed control knob. With the CAD now fully polished and the files ready for production, the design phase of this project is officially complete.

![](https://fabricate.hackclub-assets.com/14b5200b530a977cd2252cc71d139907b1382b255c93a41678be05c273b4732e/Screenshot%202026-09-28%20at%203.09.33%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/13e9c262111f761e32c6e95c2992adac10b9d08eeb0ead0989ab864234b3193c/Screenshot%202026-09-28%20at%203.09.42%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/ca3fae30e299779e28427423429a471dc3cd714303cb84f62b0712bc0e1359ed/Screenshot%202026-09-28%20at%203.10.03%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/3dfdb49b13d92192450d89e49f6dce0f01cebc075a84845d16e7ac3df2026fbb/Screenshot%202026-09-28%20at%203.10.10%E2%80%AFPM.png)

Timelapse: https://lapse.hackclub.com/timelapse/4P_LIRiZ8tWC

**Total time spent: 42m**
