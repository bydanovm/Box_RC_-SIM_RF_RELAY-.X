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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
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
SOURCEFILES_QUOTED_IF_SPACED=newmain.c config.c lcd.c Bb_device.c menu.c shift_registr.c temp_ntc.c spi_flash.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/newmain.p1 ${OBJECTDIR}/config.p1 ${OBJECTDIR}/lcd.p1 ${OBJECTDIR}/Bb_device.p1 ${OBJECTDIR}/menu.p1 ${OBJECTDIR}/shift_registr.p1 ${OBJECTDIR}/temp_ntc.p1 ${OBJECTDIR}/spi_flash.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/newmain.p1.d ${OBJECTDIR}/config.p1.d ${OBJECTDIR}/lcd.p1.d ${OBJECTDIR}/Bb_device.p1.d ${OBJECTDIR}/menu.p1.d ${OBJECTDIR}/shift_registr.p1.d ${OBJECTDIR}/temp_ntc.p1.d ${OBJECTDIR}/spi_flash.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/newmain.p1 ${OBJECTDIR}/config.p1 ${OBJECTDIR}/lcd.p1 ${OBJECTDIR}/Bb_device.p1 ${OBJECTDIR}/menu.p1 ${OBJECTDIR}/shift_registr.p1 ${OBJECTDIR}/temp_ntc.p1 ${OBJECTDIR}/spi_flash.p1

# Source Files
SOURCEFILES=newmain.c config.c lcd.c Bb_device.c menu.c shift_registr.c temp_ntc.c spi_flash.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F76
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/newmain.p1: newmain.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.p1.d 
	@${RM} ${OBJECTDIR}/newmain.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/newmain.p1 newmain.c 
	@-${MV} ${OBJECTDIR}/newmain.d ${OBJECTDIR}/newmain.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/newmain.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/config.p1: config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config.p1.d 
	@${RM} ${OBJECTDIR}/config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/config.p1 config.c 
	@-${MV} ${OBJECTDIR}/config.d ${OBJECTDIR}/config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/lcd.p1: lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.p1.d 
	@${RM} ${OBJECTDIR}/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/lcd.p1 lcd.c 
	@-${MV} ${OBJECTDIR}/lcd.d ${OBJECTDIR}/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Bb_device.p1: Bb_device.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Bb_device.p1.d 
	@${RM} ${OBJECTDIR}/Bb_device.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Bb_device.p1 Bb_device.c 
	@-${MV} ${OBJECTDIR}/Bb_device.d ${OBJECTDIR}/Bb_device.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Bb_device.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/menu.p1: menu.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/menu.p1.d 
	@${RM} ${OBJECTDIR}/menu.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/menu.p1 menu.c 
	@-${MV} ${OBJECTDIR}/menu.d ${OBJECTDIR}/menu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/shift_registr.p1: shift_registr.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/shift_registr.p1.d 
	@${RM} ${OBJECTDIR}/shift_registr.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/shift_registr.p1 shift_registr.c 
	@-${MV} ${OBJECTDIR}/shift_registr.d ${OBJECTDIR}/shift_registr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/shift_registr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/temp_ntc.p1: temp_ntc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/temp_ntc.p1.d 
	@${RM} ${OBJECTDIR}/temp_ntc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/temp_ntc.p1 temp_ntc.c 
	@-${MV} ${OBJECTDIR}/temp_ntc.d ${OBJECTDIR}/temp_ntc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/temp_ntc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/spi_flash.p1: spi_flash.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi_flash.p1.d 
	@${RM} ${OBJECTDIR}/spi_flash.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/spi_flash.p1 spi_flash.c 
	@-${MV} ${OBJECTDIR}/spi_flash.d ${OBJECTDIR}/spi_flash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/spi_flash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/newmain.p1: newmain.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.p1.d 
	@${RM} ${OBJECTDIR}/newmain.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/newmain.p1 newmain.c 
	@-${MV} ${OBJECTDIR}/newmain.d ${OBJECTDIR}/newmain.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/newmain.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/config.p1: config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config.p1.d 
	@${RM} ${OBJECTDIR}/config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/config.p1 config.c 
	@-${MV} ${OBJECTDIR}/config.d ${OBJECTDIR}/config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/lcd.p1: lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.p1.d 
	@${RM} ${OBJECTDIR}/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/lcd.p1 lcd.c 
	@-${MV} ${OBJECTDIR}/lcd.d ${OBJECTDIR}/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Bb_device.p1: Bb_device.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Bb_device.p1.d 
	@${RM} ${OBJECTDIR}/Bb_device.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Bb_device.p1 Bb_device.c 
	@-${MV} ${OBJECTDIR}/Bb_device.d ${OBJECTDIR}/Bb_device.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Bb_device.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/menu.p1: menu.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/menu.p1.d 
	@${RM} ${OBJECTDIR}/menu.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/menu.p1 menu.c 
	@-${MV} ${OBJECTDIR}/menu.d ${OBJECTDIR}/menu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/shift_registr.p1: shift_registr.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/shift_registr.p1.d 
	@${RM} ${OBJECTDIR}/shift_registr.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/shift_registr.p1 shift_registr.c 
	@-${MV} ${OBJECTDIR}/shift_registr.d ${OBJECTDIR}/shift_registr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/shift_registr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/temp_ntc.p1: temp_ntc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/temp_ntc.p1.d 
	@${RM} ${OBJECTDIR}/temp_ntc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/temp_ntc.p1 temp_ntc.c 
	@-${MV} ${OBJECTDIR}/temp_ntc.d ${OBJECTDIR}/temp_ntc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/temp_ntc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/spi_flash.p1: spi_flash.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi_flash.p1.d 
	@${RM} ${OBJECTDIR}/spi_flash.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/spi_flash.p1 spi_flash.c 
	@-${MV} ${OBJECTDIR}/spi_flash.d ${OBJECTDIR}/spi_flash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/spi_flash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c90 -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O2 -fasmfile -maddrqual=request -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Box_RF_DI_NTC_RELAY_SPI.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
