
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_LIS3DH` class instance
    auto sensor = getValue<input_DEV>(ctx);

    sensors_event_t event;
    sensor->getEvent(&event);

    emitValue<output_X>(ctx, event.acceleration.x);
    emitValue<output_Y>(ctx, event.acceleration.y);
    emitValue<output_Z>(ctx, event.acceleration.z);
    emitValue<output_DONE>(ctx, 1);
}
