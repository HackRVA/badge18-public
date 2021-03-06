#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-pic32mx_usb_badge_int_dyn.mk)" "nbproject/Makefile-local-pic32mx_usb_badge_int_dyn.mk"
include nbproject/Makefile-local-pic32mx_usb_badge_int_dyn.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=pic32mx_usb_badge_int_dyn
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/harmony_badge_2018.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/harmony_badge_2018.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/badge_apps/blinkenlights.c ../src/badge_apps/conductor.c ../src/badge_apps/adc.c ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/clk/src/sys_clk_static.c ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/ports/src/sys_ports_static.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_init.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_exceptions.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_tasks.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt_a.S ../src/system_config/pic32mx_usb_badge_int_dyn/rtos_hooks.c ../src/app.c ../src/main.c ../src/LCDcolor.c ../src/assetList.c ../src/assets.c ../src/fb.c ../src/S6B33.c ../src/badge_menu.c ../src/buttons.c ../src/utils.c ../src/ir.c ../src/timer1_int.c ../src/debug.c ../src/flash.c ../src/settings.c ../src/schedule.c ../src/adc_int.c ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs.c ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs_device.c ../../../microchip/harmony/v1_09/framework/osal/src/osal_freertos.c ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon.c ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon_pic32mx.c ../../../microchip/harmony/v1_09/framework/system/int/src/sys_int_pic32.c ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device.c ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc.c ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc_acm.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_4.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/croutine.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/list.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/queue.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/tasks.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/timers.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/event_groups.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1022150968/blinkenlights.o ${OBJECTDIR}/_ext/1022150968/conductor.o ${OBJECTDIR}/_ext/1022150968/adc.o ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o ${OBJECTDIR}/_ext/860438519/sys_ports_static.o ${OBJECTDIR}/_ext/60484592/system_init.o ${OBJECTDIR}/_ext/60484592/system_interrupt.o ${OBJECTDIR}/_ext/60484592/system_exceptions.o ${OBJECTDIR}/_ext/60484592/system_tasks.o ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o ${OBJECTDIR}/_ext/60484592/rtos_hooks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/LCDcolor.o ${OBJECTDIR}/_ext/1360937237/assetList.o ${OBJECTDIR}/_ext/1360937237/assets.o ${OBJECTDIR}/_ext/1360937237/fb.o ${OBJECTDIR}/_ext/1360937237/S6B33.o ${OBJECTDIR}/_ext/1360937237/badge_menu.o ${OBJECTDIR}/_ext/1360937237/buttons.o ${OBJECTDIR}/_ext/1360937237/utils.o ${OBJECTDIR}/_ext/1360937237/ir.o ${OBJECTDIR}/_ext/1360937237/timer1_int.o ${OBJECTDIR}/_ext/1360937237/debug.o ${OBJECTDIR}/_ext/1360937237/flash.o ${OBJECTDIR}/_ext/1360937237/settings.o ${OBJECTDIR}/_ext/1360937237/schedule.o ${OBJECTDIR}/_ext/1360937237/adc_int.o ${OBJECTDIR}/_ext/41450514/drv_usbfs.o ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o ${OBJECTDIR}/_ext/1304348434/osal_freertos.o ${OBJECTDIR}/_ext/396235064/sys_devcon.o ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o ${OBJECTDIR}/_ext/914987073/usb_device.o ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o ${OBJECTDIR}/_ext/1100007116/heap_4.o ${OBJECTDIR}/_ext/442717535/port.o ${OBJECTDIR}/_ext/442717535/port_asm.o ${OBJECTDIR}/_ext/398845687/croutine.o ${OBJECTDIR}/_ext/398845687/list.o ${OBJECTDIR}/_ext/398845687/queue.o ${OBJECTDIR}/_ext/398845687/tasks.o ${OBJECTDIR}/_ext/398845687/timers.o ${OBJECTDIR}/_ext/398845687/event_groups.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1022150968/blinkenlights.o.d ${OBJECTDIR}/_ext/1022150968/conductor.o.d ${OBJECTDIR}/_ext/1022150968/adc.o.d ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o.d ${OBJECTDIR}/_ext/860438519/sys_ports_static.o.d ${OBJECTDIR}/_ext/60484592/system_init.o.d ${OBJECTDIR}/_ext/60484592/system_interrupt.o.d ${OBJECTDIR}/_ext/60484592/system_exceptions.o.d ${OBJECTDIR}/_ext/60484592/system_tasks.o.d ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.d ${OBJECTDIR}/_ext/60484592/rtos_hooks.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/LCDcolor.o.d ${OBJECTDIR}/_ext/1360937237/assetList.o.d ${OBJECTDIR}/_ext/1360937237/assets.o.d ${OBJECTDIR}/_ext/1360937237/fb.o.d ${OBJECTDIR}/_ext/1360937237/S6B33.o.d ${OBJECTDIR}/_ext/1360937237/badge_menu.o.d ${OBJECTDIR}/_ext/1360937237/buttons.o.d ${OBJECTDIR}/_ext/1360937237/utils.o.d ${OBJECTDIR}/_ext/1360937237/ir.o.d ${OBJECTDIR}/_ext/1360937237/timer1_int.o.d ${OBJECTDIR}/_ext/1360937237/debug.o.d ${OBJECTDIR}/_ext/1360937237/flash.o.d ${OBJECTDIR}/_ext/1360937237/settings.o.d ${OBJECTDIR}/_ext/1360937237/schedule.o.d ${OBJECTDIR}/_ext/1360937237/adc_int.o.d ${OBJECTDIR}/_ext/41450514/drv_usbfs.o.d ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o.d ${OBJECTDIR}/_ext/1304348434/osal_freertos.o.d ${OBJECTDIR}/_ext/396235064/sys_devcon.o.d ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o.d ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o.d ${OBJECTDIR}/_ext/914987073/usb_device.o.d ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o.d ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o.d ${OBJECTDIR}/_ext/1100007116/heap_4.o.d ${OBJECTDIR}/_ext/442717535/port.o.d ${OBJECTDIR}/_ext/442717535/port_asm.o.d ${OBJECTDIR}/_ext/398845687/croutine.o.d ${OBJECTDIR}/_ext/398845687/list.o.d ${OBJECTDIR}/_ext/398845687/queue.o.d ${OBJECTDIR}/_ext/398845687/tasks.o.d ${OBJECTDIR}/_ext/398845687/timers.o.d ${OBJECTDIR}/_ext/398845687/event_groups.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1022150968/blinkenlights.o ${OBJECTDIR}/_ext/1022150968/conductor.o ${OBJECTDIR}/_ext/1022150968/adc.o ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o ${OBJECTDIR}/_ext/860438519/sys_ports_static.o ${OBJECTDIR}/_ext/60484592/system_init.o ${OBJECTDIR}/_ext/60484592/system_interrupt.o ${OBJECTDIR}/_ext/60484592/system_exceptions.o ${OBJECTDIR}/_ext/60484592/system_tasks.o ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o ${OBJECTDIR}/_ext/60484592/rtos_hooks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/LCDcolor.o ${OBJECTDIR}/_ext/1360937237/assetList.o ${OBJECTDIR}/_ext/1360937237/assets.o ${OBJECTDIR}/_ext/1360937237/fb.o ${OBJECTDIR}/_ext/1360937237/S6B33.o ${OBJECTDIR}/_ext/1360937237/badge_menu.o ${OBJECTDIR}/_ext/1360937237/buttons.o ${OBJECTDIR}/_ext/1360937237/utils.o ${OBJECTDIR}/_ext/1360937237/ir.o ${OBJECTDIR}/_ext/1360937237/timer1_int.o ${OBJECTDIR}/_ext/1360937237/debug.o ${OBJECTDIR}/_ext/1360937237/flash.o ${OBJECTDIR}/_ext/1360937237/settings.o ${OBJECTDIR}/_ext/1360937237/schedule.o ${OBJECTDIR}/_ext/1360937237/adc_int.o ${OBJECTDIR}/_ext/41450514/drv_usbfs.o ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o ${OBJECTDIR}/_ext/1304348434/osal_freertos.o ${OBJECTDIR}/_ext/396235064/sys_devcon.o ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o ${OBJECTDIR}/_ext/914987073/usb_device.o ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o ${OBJECTDIR}/_ext/1100007116/heap_4.o ${OBJECTDIR}/_ext/442717535/port.o ${OBJECTDIR}/_ext/442717535/port_asm.o ${OBJECTDIR}/_ext/398845687/croutine.o ${OBJECTDIR}/_ext/398845687/list.o ${OBJECTDIR}/_ext/398845687/queue.o ${OBJECTDIR}/_ext/398845687/tasks.o ${OBJECTDIR}/_ext/398845687/timers.o ${OBJECTDIR}/_ext/398845687/event_groups.o

# Source Files
SOURCEFILES=../src/badge_apps/blinkenlights.c ../src/badge_apps/conductor.c ../src/badge_apps/adc.c ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/clk/src/sys_clk_static.c ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/ports/src/sys_ports_static.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_init.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_exceptions.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_tasks.c ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt_a.S ../src/system_config/pic32mx_usb_badge_int_dyn/rtos_hooks.c ../src/app.c ../src/main.c ../src/LCDcolor.c ../src/assetList.c ../src/assets.c ../src/fb.c ../src/S6B33.c ../src/badge_menu.c ../src/buttons.c ../src/utils.c ../src/ir.c ../src/timer1_int.c ../src/debug.c ../src/flash.c ../src/settings.c ../src/schedule.c ../src/adc_int.c ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs.c ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs_device.c ../../../microchip/harmony/v1_09/framework/osal/src/osal_freertos.c ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon.c ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon_pic32mx.c ../../../microchip/harmony/v1_09/framework/system/int/src/sys_int_pic32.c ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device.c ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc.c ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc_acm.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_4.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/croutine.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/list.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/queue.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/tasks.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/timers.c ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/event_groups.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-pic32mx_usb_badge_int_dyn.mk dist/${CND_CONF}/${IMAGE_TYPE}/harmony_badge_2018.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX270F256D
MP_LINKER_FILE_OPTION=,--script="../src/app_32MX270F256D.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/60484592/system_interrupt_a.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt_a.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.ok ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.d" "${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -DPICkit3PlatformTool=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/include" -I"../src/system_config/pic32mx_usb_badge_int_dyn" -MMD -MF "${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.d"  -o ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt_a.S  -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=PICkit3PlatformTool=1 -I"../src/include" -I"../src/assets",-I"../src"
	
${OBJECTDIR}/_ext/442717535/port_asm.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/442717535" 
	@${RM} ${OBJECTDIR}/_ext/442717535/port_asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/442717535/port_asm.o 
	@${RM} ${OBJECTDIR}/_ext/442717535/port_asm.o.ok ${OBJECTDIR}/_ext/442717535/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/442717535/port_asm.o.d" "${OBJECTDIR}/_ext/442717535/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -DPICkit3PlatformTool=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/include" -I"../src/system_config/pic32mx_usb_badge_int_dyn" -MMD -MF "${OBJECTDIR}/_ext/442717535/port_asm.o.d"  -o ${OBJECTDIR}/_ext/442717535/port_asm.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/442717535/port_asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=PICkit3PlatformTool=1 -I"../src/include" -I"../src/assets",-I"../src"
	
else
${OBJECTDIR}/_ext/60484592/system_interrupt_a.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt_a.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.ok ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.d" "${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/include" -I"../src/system_config/pic32mx_usb_badge_int_dyn" -MMD -MF "${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.d"  -o ${OBJECTDIR}/_ext/60484592/system_interrupt_a.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt_a.S  -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/60484592/system_interrupt_a.o.asm.d",--gdwarf-2 -I"../src/include" -I"../src/assets",-I"../src"
	
${OBJECTDIR}/_ext/442717535/port_asm.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/442717535" 
	@${RM} ${OBJECTDIR}/_ext/442717535/port_asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/442717535/port_asm.o 
	@${RM} ${OBJECTDIR}/_ext/442717535/port_asm.o.ok ${OBJECTDIR}/_ext/442717535/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/442717535/port_asm.o.d" "${OBJECTDIR}/_ext/442717535/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/include" -I"../src/system_config/pic32mx_usb_badge_int_dyn" -MMD -MF "${OBJECTDIR}/_ext/442717535/port_asm.o.d"  -o ${OBJECTDIR}/_ext/442717535/port_asm.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/442717535/port_asm.o.asm.d",--gdwarf-2 -I"../src/include" -I"../src/assets",-I"../src"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1022150968/blinkenlights.o: ../src/badge_apps/blinkenlights.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022150968" 
	@${RM} ${OBJECTDIR}/_ext/1022150968/blinkenlights.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022150968/blinkenlights.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022150968/blinkenlights.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1022150968/blinkenlights.o.d" -o ${OBJECTDIR}/_ext/1022150968/blinkenlights.o ../src/badge_apps/blinkenlights.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1022150968/conductor.o: ../src/badge_apps/conductor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022150968" 
	@${RM} ${OBJECTDIR}/_ext/1022150968/conductor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022150968/conductor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022150968/conductor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1022150968/conductor.o.d" -o ${OBJECTDIR}/_ext/1022150968/conductor.o ../src/badge_apps/conductor.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1022150968/adc.o: ../src/badge_apps/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022150968" 
	@${RM} ${OBJECTDIR}/_ext/1022150968/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022150968/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022150968/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1022150968/adc.o.d" -o ${OBJECTDIR}/_ext/1022150968/adc.o ../src/badge_apps/adc.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2013619463/sys_clk_static.o: ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/clk/src/sys_clk_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2013619463" 
	@${RM} ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2013619463/sys_clk_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/2013619463/sys_clk_static.o.d" -o ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/clk/src/sys_clk_static.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/860438519/sys_ports_static.o: ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/860438519" 
	@${RM} ${OBJECTDIR}/_ext/860438519/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/860438519/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/860438519/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/860438519/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/860438519/sys_ports_static.o ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/ports/src/sys_ports_static.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/system_init.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/system_init.o.d" -o ${OBJECTDIR}/_ext/60484592/system_init.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_init.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/system_interrupt.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/60484592/system_interrupt.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/system_exceptions.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/60484592/system_exceptions.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_exceptions.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/system_tasks.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/system_tasks.o.d" -o ${OBJECTDIR}/_ext/60484592/system_tasks.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_tasks.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/rtos_hooks.o: ../src/system_config/pic32mx_usb_badge_int_dyn/rtos_hooks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/rtos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/rtos_hooks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/rtos_hooks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/rtos_hooks.o.d" -o ${OBJECTDIR}/_ext/60484592/rtos_hooks.o ../src/system_config/pic32mx_usb_badge_int_dyn/rtos_hooks.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/LCDcolor.o: ../src/LCDcolor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCDcolor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCDcolor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/LCDcolor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCDcolor.o.d" -o ${OBJECTDIR}/_ext/1360937237/LCDcolor.o ../src/LCDcolor.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/assetList.o: ../src/assetList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/assetList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/assetList.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/assetList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/assetList.o.d" -o ${OBJECTDIR}/_ext/1360937237/assetList.o ../src/assetList.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/assets.o: ../src/assets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/assets.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/assets.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/assets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/assets.o.d" -o ${OBJECTDIR}/_ext/1360937237/assets.o ../src/assets.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/fb.o: ../src/fb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fb.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/fb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/fb.o.d" -o ${OBJECTDIR}/_ext/1360937237/fb.o ../src/fb.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/S6B33.o: ../src/S6B33.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/S6B33.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/S6B33.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/S6B33.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/S6B33.o.d" -o ${OBJECTDIR}/_ext/1360937237/S6B33.o ../src/S6B33.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/badge_menu.o: ../src/badge_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/badge_menu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/badge_menu.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/badge_menu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/badge_menu.o.d" -o ${OBJECTDIR}/_ext/1360937237/badge_menu.o ../src/badge_menu.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/buttons.o: ../src/buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/buttons.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/buttons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/buttons.o.d" -o ${OBJECTDIR}/_ext/1360937237/buttons.o ../src/buttons.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/utils.o: ../src/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/utils.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/utils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/utils.o.d" -o ${OBJECTDIR}/_ext/1360937237/utils.o ../src/utils.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ir.o: ../src/ir.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ir.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ir.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ir.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/ir.o.d" -o ${OBJECTDIR}/_ext/1360937237/ir.o ../src/ir.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/timer1_int.o: ../src/timer1_int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer1_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer1_int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/timer1_int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/timer1_int.o.d" -o ${OBJECTDIR}/_ext/1360937237/timer1_int.o ../src/timer1_int.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/debug.o: ../src/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/debug.o.d" -o ${OBJECTDIR}/_ext/1360937237/debug.o ../src/debug.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/flash.o: ../src/flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/flash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/flash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/flash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/flash.o.d" -o ${OBJECTDIR}/_ext/1360937237/flash.o ../src/flash.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/settings.o: ../src/settings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/settings.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/settings.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/settings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/settings.o.d" -o ${OBJECTDIR}/_ext/1360937237/settings.o ../src/settings.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/schedule.o: ../src/schedule.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/schedule.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/schedule.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/schedule.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/schedule.o.d" -o ${OBJECTDIR}/_ext/1360937237/schedule.o ../src/schedule.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/adc_int.o: ../src/adc_int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/adc_int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/adc_int.o.d" -o ${OBJECTDIR}/_ext/1360937237/adc_int.o ../src/adc_int.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/41450514/drv_usbfs.o: ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/41450514" 
	@${RM} ${OBJECTDIR}/_ext/41450514/drv_usbfs.o.d 
	@${RM} ${OBJECTDIR}/_ext/41450514/drv_usbfs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/41450514/drv_usbfs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/41450514/drv_usbfs.o.d" -o ${OBJECTDIR}/_ext/41450514/drv_usbfs.o ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o: ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/41450514" 
	@${RM} ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o.d" -o ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs_device.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1304348434/osal_freertos.o: ../../../microchip/harmony/v1_09/framework/osal/src/osal_freertos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1304348434" 
	@${RM} ${OBJECTDIR}/_ext/1304348434/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/1304348434/osal_freertos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1304348434/osal_freertos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1304348434/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/1304348434/osal_freertos.o ../../../microchip/harmony/v1_09/framework/osal/src/osal_freertos.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/396235064/sys_devcon.o: ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/396235064" 
	@${RM} ${OBJECTDIR}/_ext/396235064/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/396235064/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/396235064/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/396235064/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/396235064/sys_devcon.o ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o: ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/396235064" 
	@${RM} ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/164130706/sys_int_pic32.o: ../../../microchip/harmony/v1_09/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/164130706" 
	@${RM} ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/164130706/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/164130706/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o ../../../microchip/harmony/v1_09/framework/system/int/src/sys_int_pic32.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/914987073/usb_device.o: ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914987073" 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914987073/usb_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/914987073/usb_device.o.d" -o ${OBJECTDIR}/_ext/914987073/usb_device.o ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/914987073/usb_device_cdc.o: ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914987073" 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914987073/usb_device_cdc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/914987073/usb_device_cdc.o.d" -o ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o: ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc_acm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914987073" 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o.d 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o.d" -o ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc_acm.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1100007116/heap_4.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1100007116" 
	@${RM} ${OBJECTDIR}/_ext/1100007116/heap_4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1100007116/heap_4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1100007116/heap_4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1100007116/heap_4.o.d" -o ${OBJECTDIR}/_ext/1100007116/heap_4.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_4.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/442717535/port.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/442717535" 
	@${RM} ${OBJECTDIR}/_ext/442717535/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/442717535/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/442717535/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/442717535/port.o.d" -o ${OBJECTDIR}/_ext/442717535/port.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/croutine.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/croutine.o.d" -o ${OBJECTDIR}/_ext/398845687/croutine.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/list.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/list.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/list.o.d" -o ${OBJECTDIR}/_ext/398845687/list.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/queue.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/queue.o.d" -o ${OBJECTDIR}/_ext/398845687/queue.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/tasks.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/tasks.o.d" -o ${OBJECTDIR}/_ext/398845687/tasks.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/tasks.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/timers.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/timers.o.d" -o ${OBJECTDIR}/_ext/398845687/timers.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/event_groups.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/event_groups.o.d" -o ${OBJECTDIR}/_ext/398845687/event_groups.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1022150968/blinkenlights.o: ../src/badge_apps/blinkenlights.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022150968" 
	@${RM} ${OBJECTDIR}/_ext/1022150968/blinkenlights.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022150968/blinkenlights.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022150968/blinkenlights.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1022150968/blinkenlights.o.d" -o ${OBJECTDIR}/_ext/1022150968/blinkenlights.o ../src/badge_apps/blinkenlights.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1022150968/conductor.o: ../src/badge_apps/conductor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022150968" 
	@${RM} ${OBJECTDIR}/_ext/1022150968/conductor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022150968/conductor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022150968/conductor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1022150968/conductor.o.d" -o ${OBJECTDIR}/_ext/1022150968/conductor.o ../src/badge_apps/conductor.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1022150968/adc.o: ../src/badge_apps/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022150968" 
	@${RM} ${OBJECTDIR}/_ext/1022150968/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022150968/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022150968/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1022150968/adc.o.d" -o ${OBJECTDIR}/_ext/1022150968/adc.o ../src/badge_apps/adc.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2013619463/sys_clk_static.o: ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/clk/src/sys_clk_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2013619463" 
	@${RM} ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2013619463/sys_clk_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/2013619463/sys_clk_static.o.d" -o ${OBJECTDIR}/_ext/2013619463/sys_clk_static.o ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/clk/src/sys_clk_static.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/860438519/sys_ports_static.o: ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/860438519" 
	@${RM} ${OBJECTDIR}/_ext/860438519/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/860438519/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/860438519/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/860438519/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/860438519/sys_ports_static.o ../src/system_config/pic32mx_usb_badge_int_dyn/framework/system/ports/src/sys_ports_static.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/system_init.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/system_init.o.d" -o ${OBJECTDIR}/_ext/60484592/system_init.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_init.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/system_interrupt.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/60484592/system_interrupt.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_interrupt.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/system_exceptions.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/60484592/system_exceptions.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_exceptions.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/system_tasks.o: ../src/system_config/pic32mx_usb_badge_int_dyn/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/system_tasks.o.d" -o ${OBJECTDIR}/_ext/60484592/system_tasks.o ../src/system_config/pic32mx_usb_badge_int_dyn/system_tasks.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/60484592/rtos_hooks.o: ../src/system_config/pic32mx_usb_badge_int_dyn/rtos_hooks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/60484592" 
	@${RM} ${OBJECTDIR}/_ext/60484592/rtos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/60484592/rtos_hooks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/60484592/rtos_hooks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/60484592/rtos_hooks.o.d" -o ${OBJECTDIR}/_ext/60484592/rtos_hooks.o ../src/system_config/pic32mx_usb_badge_int_dyn/rtos_hooks.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/LCDcolor.o: ../src/LCDcolor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCDcolor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCDcolor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/LCDcolor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCDcolor.o.d" -o ${OBJECTDIR}/_ext/1360937237/LCDcolor.o ../src/LCDcolor.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/assetList.o: ../src/assetList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/assetList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/assetList.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/assetList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/assetList.o.d" -o ${OBJECTDIR}/_ext/1360937237/assetList.o ../src/assetList.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/assets.o: ../src/assets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/assets.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/assets.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/assets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/assets.o.d" -o ${OBJECTDIR}/_ext/1360937237/assets.o ../src/assets.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/fb.o: ../src/fb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fb.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/fb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/fb.o.d" -o ${OBJECTDIR}/_ext/1360937237/fb.o ../src/fb.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/S6B33.o: ../src/S6B33.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/S6B33.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/S6B33.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/S6B33.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/S6B33.o.d" -o ${OBJECTDIR}/_ext/1360937237/S6B33.o ../src/S6B33.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/badge_menu.o: ../src/badge_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/badge_menu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/badge_menu.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/badge_menu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/badge_menu.o.d" -o ${OBJECTDIR}/_ext/1360937237/badge_menu.o ../src/badge_menu.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/buttons.o: ../src/buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/buttons.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/buttons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/buttons.o.d" -o ${OBJECTDIR}/_ext/1360937237/buttons.o ../src/buttons.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/utils.o: ../src/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/utils.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/utils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/utils.o.d" -o ${OBJECTDIR}/_ext/1360937237/utils.o ../src/utils.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ir.o: ../src/ir.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ir.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ir.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ir.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/ir.o.d" -o ${OBJECTDIR}/_ext/1360937237/ir.o ../src/ir.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/timer1_int.o: ../src/timer1_int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer1_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer1_int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/timer1_int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/timer1_int.o.d" -o ${OBJECTDIR}/_ext/1360937237/timer1_int.o ../src/timer1_int.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/debug.o: ../src/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/debug.o.d" -o ${OBJECTDIR}/_ext/1360937237/debug.o ../src/debug.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/flash.o: ../src/flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/flash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/flash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/flash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/flash.o.d" -o ${OBJECTDIR}/_ext/1360937237/flash.o ../src/flash.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/settings.o: ../src/settings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/settings.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/settings.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/settings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/settings.o.d" -o ${OBJECTDIR}/_ext/1360937237/settings.o ../src/settings.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/schedule.o: ../src/schedule.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/schedule.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/schedule.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/schedule.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/schedule.o.d" -o ${OBJECTDIR}/_ext/1360937237/schedule.o ../src/schedule.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/adc_int.o: ../src/adc_int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/adc_int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1360937237/adc_int.o.d" -o ${OBJECTDIR}/_ext/1360937237/adc_int.o ../src/adc_int.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/41450514/drv_usbfs.o: ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/41450514" 
	@${RM} ${OBJECTDIR}/_ext/41450514/drv_usbfs.o.d 
	@${RM} ${OBJECTDIR}/_ext/41450514/drv_usbfs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/41450514/drv_usbfs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/41450514/drv_usbfs.o.d" -o ${OBJECTDIR}/_ext/41450514/drv_usbfs.o ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o: ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/41450514" 
	@${RM} ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o.d" -o ${OBJECTDIR}/_ext/41450514/drv_usbfs_device.o ../../../microchip/harmony/v1_09/framework/driver/usb/usbfs/src/dynamic/drv_usbfs_device.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1304348434/osal_freertos.o: ../../../microchip/harmony/v1_09/framework/osal/src/osal_freertos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1304348434" 
	@${RM} ${OBJECTDIR}/_ext/1304348434/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/1304348434/osal_freertos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1304348434/osal_freertos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1304348434/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/1304348434/osal_freertos.o ../../../microchip/harmony/v1_09/framework/osal/src/osal_freertos.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/396235064/sys_devcon.o: ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/396235064" 
	@${RM} ${OBJECTDIR}/_ext/396235064/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/396235064/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/396235064/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/396235064/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/396235064/sys_devcon.o ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o: ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/396235064" 
	@${RM} ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/396235064/sys_devcon_pic32mx.o ../../../microchip/harmony/v1_09/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/164130706/sys_int_pic32.o: ../../../microchip/harmony/v1_09/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/164130706" 
	@${RM} ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/164130706/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/164130706/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/164130706/sys_int_pic32.o ../../../microchip/harmony/v1_09/framework/system/int/src/sys_int_pic32.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/914987073/usb_device.o: ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914987073" 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914987073/usb_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/914987073/usb_device.o.d" -o ${OBJECTDIR}/_ext/914987073/usb_device.o ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/914987073/usb_device_cdc.o: ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914987073" 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914987073/usb_device_cdc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/914987073/usb_device_cdc.o.d" -o ${OBJECTDIR}/_ext/914987073/usb_device_cdc.o ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o: ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc_acm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914987073" 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o.d 
	@${RM} ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o.d" -o ${OBJECTDIR}/_ext/914987073/usb_device_cdc_acm.o ../../../microchip/harmony/v1_09/framework/usb/src/dynamic/usb_device_cdc_acm.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1100007116/heap_4.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1100007116" 
	@${RM} ${OBJECTDIR}/_ext/1100007116/heap_4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1100007116/heap_4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1100007116/heap_4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/1100007116/heap_4.o.d" -o ${OBJECTDIR}/_ext/1100007116/heap_4.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_4.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/442717535/port.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/442717535" 
	@${RM} ${OBJECTDIR}/_ext/442717535/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/442717535/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/442717535/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/442717535/port.o.d" -o ${OBJECTDIR}/_ext/442717535/port.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/croutine.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/croutine.o.d" -o ${OBJECTDIR}/_ext/398845687/croutine.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/list.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/list.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/list.o.d" -o ${OBJECTDIR}/_ext/398845687/list.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/queue.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/queue.o.d" -o ${OBJECTDIR}/_ext/398845687/queue.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/tasks.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/tasks.o.d" -o ${OBJECTDIR}/_ext/398845687/tasks.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/tasks.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/timers.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/timers.o.d" -o ${OBJECTDIR}/_ext/398845687/timers.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/398845687/event_groups.o: ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/398845687" 
	@${RM} ${OBJECTDIR}/_ext/398845687/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/398845687/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/398845687/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/include" -I"../src/assets" -ffunction-sections -O1 -D_SUPPRESS_PLIB_WARNING -D__XC -MMD -MF "${OBJECTDIR}/_ext/398845687/event_groups.o.d" -o ${OBJECTDIR}/_ext/398845687/event_groups.o ../../../microchip/harmony/v1_09/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/harmony_badge_2018.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/app_32MX270F256D.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DPICkit3PlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/harmony_badge_2018.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=PICkit3PlatformTool=1,--defsym=_min_heap_size=0,--defsym=_min_stack_size=0,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--cref,-s
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/harmony_badge_2018.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/app_32MX270F256D.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/harmony_badge_2018.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mx_usb_badge_int_dyn=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--defsym=_min_stack_size=0,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--cref,-s
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/harmony_badge_2018.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/pic32mx_usb_badge_int_dyn
	${RM} -r dist/pic32mx_usb_badge_int_dyn

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
