# Ibex Simple System with coprocessor for Posits

* Edit fusesoc.conf
* Build project
    * fusesoc --config=fusesoc.conf run --target=sim --setup --build psc:ibex:ibex_simple_system --RV32M=1 --RV32E=0
* Compile code
    * export PATH=$PATH:/.../lowrisc-toolchain-rv32imc-20210412-1/bin (precompiled by lowrisc)
    * in folder SW/code/ and with makefile, make -C . (get .elf)
* Launch simulation
    * ./build/psc_ibex_ibex_simple_system_0/sim-verilator/Vibex_simple_system -t --meminit=ram,/.../file.elf

