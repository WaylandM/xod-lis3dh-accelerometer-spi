// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_LIS3DH"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

//Include C++ libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LIS3DH.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_LIS3DH*;
    }

    static_assert(isValidDigitalPort(constant_input_CS), "must be a valid digital port");
 
    // Create an object of class Adafruit_LIS3DH
    Adafruit_LIS3DH sensor = Adafruit_LIS3DH(constant_input_CS);

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        if (!sensor.begin()) {
            raiseError(ctx);
            return;
        }

        emitValue<output_DEV>(ctx, &sensor);
    }

}






