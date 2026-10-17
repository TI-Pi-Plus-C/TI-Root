# TI-Root
A program written for the TI 84 Plus CE that can solve quadratic equations in form ax^2 + bx + c and cubic equations in the form ax^3 + bx^2 + cx + d. This is a work in progress with several improvements already planned. To use download the Root.zip from the releases section and copy the Root.8xp file to your TI 84 Plus CE using ether TI Connect CE, TILP. Once copied over run by pressing "prgm" and selecting ROOT. NOTE: If you are updated past 5.4.1, (such as myself) use the ArTIfiCE jailbreak found [here](https://yvantt.github.io/arTIfiCE/) to run.

Usage:
Upon running you will enter a menu with three options: 1. Quadratic 2. Cubic 3. Exit please enter the corresponding number to select your choice (Arrow Keys currently do not work). The calculator will prompt you to type in A=, B=, C= (D= for cubic equations). Once you do hit enter and the solutions (or real roots) will appear. After the roots have been provided press "clear" to exit the program or "2nd" to enter a new equation. Imaginary solutions will be returned in a - bi form.

Building:
Download the CE programming toolchain. run make while in the source code directory and it should build successfully.

TODO:
- Add in support for storing solutions to calculator memory
- Add in support for quartic equations

(C) TI-PI-Plus-C 2026
