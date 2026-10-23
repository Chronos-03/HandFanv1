---
title: "Mini Turbo Hand Fan"
author: "Mohd Anas Anwar"
description: "A modular, high-performance DIY hand fan built with drone hardware, an ATtiny85, and a custom 3D-printed enclosure—all under a $50 budget."
created_at: "2026-09-26"
---

# September 26: Component Research



Kicking off the Mini Turbo Hand Fan project! My main task today was building the complete Bill of Materials (BOM) from scratch. The biggest problem I faced was finding hardware powerful enough to match an $80 commercial turbo fan, while keeping my total BOM strictly under the $50 grant limit. Standard DC motors wouldn't work, so I used AI to cross-reference vendors and prices to find affordable drone hardware instead.

Here are the core components I chose for the BOM to solve this:
* **Propulsion:** Emax 1404-6000KV brushless motor and a 30A ESC for massive thrust.
* **Control:** A standard ESC PWM controller module to generate the throttle signal.
* **Power:** Four 18650 Li-ion cells, paired with a 4S 30A BMS and a Type-C charger for safe, portable power.

Another challenge was remembering to add miscellaneous items to the BOM, like silicone wire, solder wire, and flux. Leaving these out would have created hidden costs that break the budget later. 

The tl;dr is: Successfully created the full BOM by carefully comparing vendors, locking in all high-performance drone electronics and essential consumables for exactly $50.00.

![BOM Spreadsheet](images/bom-spreadsheet.png)

**Total time spent: 48 minutes**

# September 26: Initial Circuit Design & Schematics

With the hardware selected, it was time to move into KiCad and build the actual electrical blueprint. Since I am doing point-to-point wiring to stay under the $50 budget, the schematic is critical for ensuring I don't accidentally short a 16.8V Li-ion pack.

The first major task was sourcing the schematic symbols for all the physical modules. The complete hardware list included: 4x 18650 Cells, 30A ESC, BLDC Motor, PWM Controller, 4S BMS (Battery Management System), Type-C Charging Module, and a Power Switch.

While basic components like the switch and motor are native to KiCad's standard libraries, specialized breakout boards like the 4S BMS, the Type-C charger, and the PWM controller required more work. I had to pull in custom component footprints and map generic connector symbols to represent their exact pinouts so the schematic would perfectly mirror the real-world hardware.

Once the symbols were staged, I routed the connections. I had to be incredibly careful with the power hierarchy:
* **High-Current Power:** I routed the four 18650 cells in series into the BMS for overcharge/discharge protection. The safe BMS output then routes through the main power switch and directly into the main power pads of the 30A ESC.
* **Charging Logic:** I wired the Type-C Charging module's outputs in parallel to the main battery rails, allowing the pack to be recharged without removing the cells.
* **Signal Logic:** I isolated the low-voltage throttle signal, routing the PWM Controller's output pin directly to the ESC's signal input.

After all connections were drawn, I ran a strict circuit verification. In KiCad, this meant running an Electrical Rules Check (ERC) to verify the circuit logic. I went through and resolved any warnings about unconnected pins or missing power flags to ensure the circuit was structurally sound before moving forward.

The tl;dr is: Successfully sourced custom symbols for all 7 primary modules and mapped out the high-current and low-voltage signal paths in KiCad. Ran ERC verifications to confirm the point-to-point architecture is electrically safe.

![KiCad Schematic](images/kicad-schematic.png)

**Total time spent: 1 hour**

# September 26: 7-Blade Impeller CAD Design

Moving from electronics into mechanical design! Today, I tackled the most critical custom part of the entire project: the 30mm impeller.

I initially wasn't sure how many blades to use, but after doing some aerodynamic research, I learned why drone props and turbines often use odd numbers. Even numbers of blades create radially opposed pairs that can trigger severe harmonic resonance and acoustic vibration—a massive problem when dealing with a 6000KV brushless motor spinning at extreme RPMs. By choosing an odd number (7 blades), the design naturally suppresses those harmonic vibrations, resulting in significantly smoother