/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* #undef WS2812_DI_PIN */
/* #define WS2812_DI_PIN 23 */
/* #undef RGBLED_NUM */
/* #define RGBLED_NUM 1 */


// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

#define ENCODER_RESOLUTION 4

// Enable double tap reset button to enter bootloader feature for RP2040.
// This feature is intended for RP2040 controllers which require 2 buttons (Reset & Boot) to enter bootloader, e.g. Splinky.
// Comment out these lines when using RP2040 controllers with single button reset / bootloader circuit, e.g. Sea Picro.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
/* #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 */
// Force master side determination by VBUS (USB voltage) detect method instead of the default USB data detect method.
// RP2040 controllers like Splinky and Sea Picro have working VBUS detect on GP19 pin.
/* #undef SPLIT_USB_DETECT */
/* #define USB_VBUS_PIN GP19 */
// Set handedness by EEPROM.
#define EE_HANDS
