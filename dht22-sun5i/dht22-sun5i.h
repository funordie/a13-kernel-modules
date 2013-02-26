/*
 * dht22-sun5i - DHT22 driver for sun5i platform
 *
 * Copyright (C) 2013 Harry Hornbacher <h.hornbacher@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 */

#define DRIVER_AUTHOR   "Harry Hornbacher <h.hornbacher@gmail.com>"
#define DRIVER_DESC     "DHT22 driver for sun5i platform"
#define DRIVER_NAME     "dht22-sun5i"
#define DRV_VERSION     "0.0.1"


#define PIN_DIR(handler,dir)    gpio_set_one_pin_io_status(handler, dir, NULL);
#define PIN_SET(handler,val)    gpio_write_one_pin_value(handler, val, NULL);
#define PIN_GET(handler)        gpio_read_one_pin_value(handler, NULL);
#define PIN_DIR_OUT                 1
#define PIN_DIR_IN                  0

struct dht22_sun5i_platform_data {
    unsigned gpio_handler;
    script_gpio_set_t info;
    int direction;
};

struct dht22_sun5i_sensor_data {
    u8 rh_i, rh_d;
    u8 tp_i, tp_d;
    u8 checksum;
    int valid;
};

static int dht22_sun5i_remove_driver(struct platform_device *pdev);
static int dht22_sun5i_probe_driver(struct platform_device *pdev);


static void dht22_sun5i_write_bit(struct dht22_sun5i_platform_data *data, u8 bit);
static u8 dht22_sun5i_read_bit(struct dht22_sun5i_platform_data *data);

static int dht22_sun5i_sensor_read(struct dht22_sun5i_platform_data *pdata);
