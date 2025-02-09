#
# Rules for building application
#

# ----------------------------------------------------------------------------
# project local config
# ----------------------------------------------------------------------------
include localconfig.mk

# ----------------------------------------------------------------------------
# common rules
# ----------------------------------------------------------------------------
ROOT_PATH := ../../../..

include $(ROOT_PATH)/gcc.mk

# ----------------------------------------------------------------------------
# project and objects
# ----------------------------------------------------------------------------
PROJECT := oxr_sharedApp

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

DIRS_IGNORE := ../gcc% ../image% ../shared% $(ROOT_PATH)/project/common/board/%
DIRS_ALL := $(shell find .. $(ROOT_PATH)/project/common -type d)
DIRS := $(filter-out $(DIRS_IGNORE),$(DIRS_ALL))
DIRS += $(ROOT_PATH)/project/common/board/$(__PRJ_CONFIG_BOARD)

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
SRCS += ../shared/src/tiny_crc8
SRCS += ../shared/src/new_ping

SRCS += ../shared/src/cmnds/cmd_channels
SRCS += ../shared/src/cmnds/cmd_eventHandlers
SRCS += ../shared/src/cmnds/cmd_main
SRCS += ../shared/src/cmnds/cmd_newLEDDriver
SRCS += ../shared/src/cmnds/cmd_repeatingEvents
SRCS += ../shared/src/cmnds/cmd_tasmota
SRCS += ../shared/src/cmnds/cmd_tcp
SRCS += ../shared/src/cmnds/cmd_test
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

$(info    Now will print SCRS list)
$(info    SRCS is $(SRCS))
$(info    SCRs list printed)

OBJS := $(addsuffix .o,$(SRCS))

# extra libs
PRJ_EXTRA_LIBS := -latcmd


# project make rules
include $(PRJ_MAKE_RULES)
