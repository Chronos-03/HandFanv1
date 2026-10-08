---
title: "Mini hand vacum+fan "
github: "https://github.com/Chronos-03/HandFanv1"
description: "making bldc based custom battery pack bldc jet fan use as mini vacumm for the cleaning also use as hand fan "
created_at: "2026-09-25"
total_time: "7h 6m"
---

# September 26, 2026: Component Research
<!-- fabricate:entry 6 -->

Kicking off the Mini Turbo Hand Fan project! My main task today was building the complete Bill of Materials (BOM) from scratch.The biggest problem I faced was finding hardware powerful enough to match an $80 commercial turbo fan, while keeping my total BOM strictly under the $50 grant limit. Standard DC motors wouldn't work, so I used AI to cross-reference vendors and prices to find affordable drone hardware instead.  

Here are the core components I chose for the BOM to solve this:

Propulsion: Emax 1404-6000KV brushless motor and a 30A ESC for massive thrust.

Control: A standard ESC PWM controller module to generate the throttle signal.

Power: Four 18650 Li-ion cells, paired with a 4S 30A BMS and a Type-C charger for safe, portable power.Another challenge was remembering to add miscellaneous items to the BOM, like silicone wire, solder wire, and flux. Leaving these out would have created hidden costs that break the budget later.  

The tl;dr is: Successfully created the full BOM by carefully comparing vendors, locking in all high-performance drone electronics and essential consumables for exactly $50.00.

![](https://fabricate.hackclub-assets.com/b538e3ed672a16f909306abf9ac1e36cb3e74ca46b1a4b5f60c638629bd783fa/Screenshot%202026-09-26%20at%203.31.04%E2%80%AFAM.png)

**Total time spent: 48m**

# September 26, 2026 (entry 2): Initial Circuit Design & Schematics
<!-- fabricate:entry 8 -->

With the hardware selected, it was time to move into KiCad and build the actual electrical blueprint. Since I am doing point-to-point wiring to stay under the $50 budget, the schematic is critical for ensuring I don't accidentally short a 16.8V Li-ion pack.

The first major task was sourcing the schematic symbols for all the physical modules. The complete hardware list included:   
4x 18650 Cells
30A ESCBLDC Motor
PWM Controller4S BMS (Battery Management System)
Type-C Charging Module
Power Switch

While basic components like the switch and motor are native to KiCad's standard libraries, specialized breakout boards like the 4S BMS, the Type-C charger, and the PWM controller required more work. I had to pull in custom component footprints and map generic connector symbols to represent their exact pinouts so the schematic would perfectly mirror the real-world hardware.   

Once the symbols were staged, I routed the connections. I had to be incredibly careful with the power hierarchy:   

High-Current Power: I routed the four 18650 cells in series into the BMS for overcharge/discharge protection. The safe BMS output then routes through the main power switch and directly into the main power pads of the 30A ESC.

Charging Logic: I wired the Type-C Charging module's outputs in parallel to the main battery rails, allowing the pack to be recharged without removing the cells.

Signal Logic: I isolated the low-voltage throttle signal, routing the PWM Controller's output pin directly to the ESC's signal input.

After all connections were drawn, I ran a strict circuit verification. In KiCad, this meant running an Electrical Rules Check (ERC) to verify the circuit logic. I went through and resolved any warnings about unconnected pins or missing power flags to ensure the circuit was structurally sound before moving forward.   

The tl;dr is: Successfully sourced custom symbols for all 7 primary modules and mapped out the high-current and low-voltage signal paths in KiCad. Ran ERC verifications to confirm the point-to-point architecture is electrically safe.

![](https://fabricate.hackclub-assets.com/6532fe5e1aa3e99c18d4fe4633132924ef6d3e7384c02e0e9d9a615b2db95a94/Screenshot%202026-09-26%20at%2011.13.02%E2%80%AFAM.png)

**Total time spent: 1h**

# September 26, 2026 (entry 3): 7-Blade Impeller CAD Design
<!-- fabricate:entry 9 -->

Moving from electronics into mechanical design! Today, I tackled the most critical custom part of the entire project: the 30mm impeller.

I initially wasn't sure how many blades to use, but after doing some aerodynamic research, I learned why drone props and turbines often use odd numbers. Even numbers of blades create radially opposed pairs that can trigger severe harmonic resonance and acoustic vibration—a massive problem when dealing with a 6000KV brushless motor spinning at extreme RPMs. By choosing an odd number (7 blades), the design naturally suppresses those harmonic vibrations, resulting in significantly smoother and quieter airflow inside a tight duct.

The primary engineering challenge was then optimizing the actual blade geometry to strike the perfect balance between static pressure generation (crucial for the vacuum function) and overall air volume displacement (CFM).
Here is how I modeled it in Fusion 360 to achieve this:

The Hub: I first modeled the central bore to perfectly match the Emax 1404 motor shaft tolerance, ensuring a tight, perfectly centered fit to prevent wobble.

The Profile: I used the Spline tool to draft a swept, backward-curved blade profile. This geometry is designed to actively channel and compress the air as it accelerates centrifugally outward.

The Array: After lofting the primary blade with the correct pitch angle, I used the Circular Pattern tool to array all 7 blades evenly around the central axis.

The Clearance: Finally, I strictly constrained the outer diameter to ensure the blade tips sit perfectly inside the planned 30mm enclosure with minimal clearance, maximizing motor efficiency without risking wall-rubbing.   

The tl;dr is: Researched acoustic resonance to settle on a vibration-dampening 7-blade design, and successfully modeled a custom swept-blade impeller in Fusion 360 optimized for high static pressure and tight 30mm tolerances.

![](https://fabricate.hackclub-assets.com/0d827d67d1e88394b67cb735a01ebe81d2c112e13d45b961dddc97de41625bda/Screenshot%202026-09-26%20at%201.20.19%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/c93d0a5ea4276f8c64a60fa224053667757f4d3ad1d76393bf1c193bbe10633b/Screenshot%202026-09-26%20at%201.20.27%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/e01aad90c80b9489e00cc7117349189c3f2b016b8ef9c4f51686d330f311d3c9/Screenshot%202026-09-26%20at%201.20.34%E2%80%AFPM.png)

**Total time spent: 1h 6m**

# September 26, 2026 (entry 4): Main Body Enclosure
<!-- fabricate:entry 10 -->

With the 30mm impeller and motor assembly (the "engine") finalized, I shifted focus to designing the primary structural housing. My core design philosophy here was modularity. Instead of a fixed, closed front end, I designed the main body around a cylindrical BLDC mount and wind tube. This specific geometry ensures that if I want to add attachments in the future—like a vacuum nozzle or an air concentrator—they can easily friction-fit onto the cylinder.

However, the CAD process quickly became a massive troubleshooting session.

The primary challenge was packaging. Attempting to seamlessly integrate four bulky 18650 Li-ion cells, a 30A ESC, and the off-the-shelf PWM controller into a compact, hand-held form factor resulted in multiple interference and geometric errors in Fusion 360. The electronics simply wanted to take up more space than the ergonomic handle allowed.   

Here is how I spent the hour resolving these spatial conflicts:

Interference Detection: I used Fusion 360’s Interference tool to locate exactly where the virtual 18650 batteries and ESC were clipping through the internal walls of the handle.   

Wall Thickness Tuning: I had to carefully adjust the shell and wall thicknesses. The walls needed to be thin enough to maximize internal volume for the electronics, but thick and rigid enough to handle the thrust and vibrations of the 6000KV motor without snapping.   

Mesh Repair: I went through the timeline and fixed multiple overlapping body warnings where the cylindrical duct intersected with the handle base, ensuring the final design was structurally sound.   

The tl;dr is: Designed a modular, cylindrical main body housing for the impeller, and spent the session meticulously resolving spatial conflicts and geometric overlaps in Fusion 360 to ensure the final STL will be fully optimized for 3D printing without manifold errors.

![](https://fabricate.hackclub-assets.com/d5b39c51f8cbc9fd4690b1d1031b9a423477ceb646051ef17843212a1665afab/Screenshot%202026-09-26%20at%203.09.53%E2%80%AFPM.png)

**Total time spent: 1h**

# September 26, 2026 (entry 5): Interface Cutouts & Ergonomic Handle Design
<!-- fabricate:entry 12 -->

With the internal spatial conflicts resolved, I shifted my focus to the external user interface and the physical ergonomics of the main body housing.

The main engineering hurdle here was seamlessly integrating the external hardware without compromising the structural integrity of the handle. I needed precise mounting points for the power switches, the PWM speed controller dial, and the Type-C USB charging module. I used sketch-driven extrusions and cuts in Fusion 360 to create these exact geometric profiles. I had to calculate extremely tight tolerances for these cutouts so the components wouldn't rattle loose under the vibrations of the 6000KV motor.

Next, I tackled wire routing, which is a major point of failure in DIY electronics. The 3-phase brushless motor wires need to pass from the main cylindrical wind tube down into the electronics compartment. I engineered a dedicated internal routing channel connecting the two zones. This allows the wires to pass through safely without getting pinched by the outer shell or protruding into the main duct to obstruct the high-velocity airflow.

Finally, I had to account for the actual physics of using the device. Because this turbo fan will generate noticeable rearward thrust, a blocky handle would cause wrist fatigue and slip. I spent the rest of the session applying heavy fillets and continuous rounding to the entire handle profile. This geometric refinement ensures a secure, comfortable ergonomic grip during handheld operation.   

The tl;dr is: Finalized the main body CAD by engineering precise interface cutouts for the I/O, a safe internal wire-routing channel for the motor phases, and heavy ergonomic filleting to counteract the physical thrust of the fan.

![](https://fabricate.hackclub-assets.com/55c9e43e75eb996fa48fcf156daf3b5adb38926378270f1510d44494970e223d/Screenshot%202026-09-26%20at%2010.23.11%E2%80%AFPM.png)

**Total time spent: 1h 30m**

# September 28, 2026: CAD Refinement & Microcontroller Pivot
<!-- fabricate:entry 31 -->

During this session, I heavily refined the main 3D body, polishing external features while precisely mapping the internal compartments to house the complete power plant: the four 18650 Li-ion batteries, the BMS, and the Type-C charging module. However, this strict spatial optimization led to a major roadblock.   

The off-the-shelf PWM speed controller I originally selected was simply too bulky to fit inside the ergonomic handle. Because I am strictly avoiding custom PCB fabrication to adhere to the $50 grant budget, utilizing bare SMD chips to save space was not an option.   

To solve this, I executed a major engineering pivot. I completely scrapped the bulky PWM controller and swapped it for a Digispark ATtiny85 development board paired with a simple rotary potentiometer.   

This hardware swap accomplishes two critical things for the project:

It allows me to write custom firmware to precisely generate the throttle signal required by the 30A ESC.   

The ATtiny85's incredibly small footprint allows me to maintain a highly compact, point-to-point wiring architecture that perfectly fits inside the refined CAD model without requiring structural compromises.   

The tl;dr is: Hit a major spatial constraint in the handle and executed a hardware pivot from a bulky PWM module to a compact ATtiny85, allowing for custom firmware control while adhering to the strict budget and point-to-point wiring limits

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

The final stretch! In this last design session, I brought everything together to complete the full CAD assembly of the Mini Turbo Hand Fan. The main objective today was creating a perfect "digital twin" to verify that all the separate sub-assemblies—the 7-blade impeller, the cylindrical wind tube, and the handle—mated together flawlessly before moving to production.

I arranged the remaining virtual internal components into their designated compartments, confirming that the new ATtiny85 hardware pivot successfully resolved the spatial conflicts from yesterday. I also performed a final tolerance check on the external housing. To ensure the handheld fan is completely comfortable to hold against the rearward thrust of the motor, I applied continuous rounded fillets across the entire handle profile.

Next, I verified the precise mounting grooves for the external interface. I checked the exact dimensional cutouts to ensure the Type-C charging module, the power button, and the rotary speed control knob will all flush-mount perfectly with the exterior shell, giving it a premium, commercial feel.

To wrap everything up, I exported the entire finalized assembly as a universal STEP file. This ensures the internal tolerances, wall thicknesses, and custom 7-blade impeller geometry can be accurately inspected during the design review.

The tl;dr is: Completed the full digital assembly, verified all internal component clearances, finalized the ergonomic fillets, and exported the production-ready STEP file. The design phase of this project is officially complete!

![](https://fabricate.hackclub-assets.com/14b5200b530a977cd2252cc71d139907b1382b255c93a41678be05c273b4732e/Screenshot%202026-09-28%20at%203.09.33%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/13e9c262111f761e32c6e95c2992adac10b9d08eeb0ead0989ab864234b3193c/Screenshot%202026-09-28%20at%203.09.42%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/ca3fae30e299779e28427423429a471dc3cd714303cb84f62b0712bc0e1359ed/Screenshot%202026-09-28%20at%203.10.03%E2%80%AFPM.png)
![](https://fabricate.hackclub-assets.com/3dfdb49b13d92192450d89e49f6dce0f01cebc075a84845d16e7ac3df2026fbb/Screenshot%202026-09-28%20at%203.10.10%E2%80%AFPM.png)

Timelapse: https://lapse.hackclub.com/timelapse/4P_LIRiZ8tWC

**Total time spent: 42m**
