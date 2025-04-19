#
# Rules for building application
#

# ----------------------------------------------------------------------------
# common rules
# ----------------------------------------------------------------------------
ROOT_PATH := ../../../..

include $(ROOT_PATH)/gcc.mk

# ----------------------------------------------------------------------------
# project name and project root path
# ----------------------------------------------------------------------------
PROJECT := $(notdir $(shell cd .. && pwd))
PRJ_PARENT_DIR := $(notdir $(shell cd ../.. && pwd))
PRJ_ROOT_PATH := $(ROOT_PATH)/project/$(PRJ_PARENT_DIR)/$(PROJECT)

# ----------------------------------------------------------------------------
# objects
# ----------------------------------------------------------------------------
INCLUDE_PATHS += -I$(PRJ_ROOT_PATH)
INCLUDE_PATHS += -I$(ROOT_PATH)/project/$(PROJECT)

DIRS_IGNORE := $(PRJ_ROOT_PATH)/gcc%
DIRS_IGNORE += $(PRJ_ROOT_PATH)/image%
DIRS_IGNORE += $(ROOT_PATH)/project/common/board/%
DIRS_IGNORE += $(ROOT_PATH)/project/common/board/$(shell echo $(CONFIG_BOARD))
DIRS_IGNORE += ../shared/%

DIRS_ALL := $(shell find .. $(ROOT_PATH)/project/common -type d)
DIRS := $(filter-out $(DIRS_IGNORE),$(DIRS_ALL))
DIRS += $(ROOT_PATH)/project/common/board/$(shell echo $(CONFIG_BOARD))

SRCS := $(basename $(foreach dir,$(DIRS),$(wildcard $(dir)/*.[csS])))

SRCS += ../shared/src/new_cfg
SRCS += ../shared/src/new_pins
SRCS += ../shared/src/new_common
SRCS += ../shared/src/rgb2hsv

SRCS += ../shared/src/httpserver/hass
SRCS += ../shared/src/httpserver/new_http
SRCS += ../shared/src/httpserver/http_tcp_server
SRCS += ../shared/src/httpserver/http_fns
SRCS += ../shared/src/httpserver/rest_interface

SRCS += ../shared/src/logging/logging
SRCS += ../shared/src/jsmn/jsmn
SRCS += ../shared/src/mqtt/new_mqtt
SRCS += ../shared/src/mqtt/new_mqtt_deduper
SRCS += ../shared/src/tiny_crc8
SRCS += ../shared/src/new_ping

SRCS += ../shared/src/cmnds/cmd_channels
SRCS += ../shared/src/cmnds/cmd_eventHandlers
SRCS += ../shared/src/cmnds/cmd_main
SRCS += ../shared/src/cmnds/cmd_newLEDDriver
SRCS += ../shared/src/cmnds/cmd_newLEDDriver_colors
SRCS += ../shared/src/cmnds/cmd_repeatingEvents
SRCS += ../shared/src/cmnds/cmd_tasmota
SRCS += ../shared/src/cmnds/cmd_tcp
SRCS += ../shared/src/cmnds/cmd_test
SRCS += ../shared/src/cmnds/cmd_if
SRCS += ../shared/src/cmnds/cmd_tokenizer

SRCS += ../shared/src/cJSON/cJSON

SRCS += ../shared/src/driver/drv_bl0942
SRCS += ../shared/src/driver/drv_main
SRCS += ../shared/src/driver/drv_ntp
SRCS += ../shared/src/driver/drv_tuyaMCU
SRCS += ../shared/src/driver/drv_uart

SRCS += ../shared/src/i2c/drv_i2c_main
SRCS += ../shared/src/i2c/drv_i2c_mcp23017
SRCS += ../shared/src/i2c/drv_i2c_tc74
SRCS += ../shared/src/i2c/drv_i2c_lcd_pcf8574t

SRCS += ../shared/src/hal/xr809/hal_adc_xr809
SRCS += ../shared/src/hal/xr809/hal_wifi_xr809
SRCS += ../shared/src/hal/xr809/hal_generic_xr809
SRCS += ../shared/src/hal/xr809/hal_main_xr809
SRCS += ../shared/src/hal/xr809/hal_pins_xr809
SRCS += ../shared/src/hal/xr809/hal_flashConfig_xr809
SRCS += ../shared/src/hal/xr809/hal_flashVars_xr809

SRCS += ../shared/src/user_main

OBJS := $(addsuffix .o,$(SRCS))

# extra libraries searching path
# PRJ_EXTRA_LIBS_PATH :=

# extra libraries
# PRJ_EXTRA_LIBS :=

# extra header files searching path
# PRJ_EXTRA_INC_PATH :=

# extra symbols (macros)
# PRJ_EXTRA_SYMBOLS :=

# ----------------------------------------------------------------------------
# override project variables
# ----------------------------------------------------------------------------
# linker script file
#   - relative to "./"
#   - define your own "LINKER_SCRIPT" to override the default one
# LINKER_SCRIPT :=

# image config file
#   - relative to "../image/$(CONFIG_CHIP_TYPE)/", eg. "../image/xr806/"
#   - define your own "IMAGE_CFG" to override the default one
# IMAGE_CFG :=

# image name, default to xr_system
# IMAGE_NAME :=

# project make rules
include $(PRJ_MAKE_RULES)
