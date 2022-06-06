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
FINAL_IMAGE=${DISTDIR}/PBLE02-firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PBLE02-firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/i2c2.c mcc_generated_files/exceptions.c mcc_generated_files/uart1.c mcc_generated_files/rtcc.c mcc_generated_files/pin_manager.c mcc_generated_files/adc1.c mcc_generated_files/tmr1.c main.c Utils.c keyboard.c lcd.c memory.c adc.c mcc_generated_files/mccp1_compare.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/i2c2.o ${OBJECTDIR}/mcc_generated_files/exceptions.o ${OBJECTDIR}/mcc_generated_files/uart1.o ${OBJECTDIR}/mcc_generated_files/rtcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/adc1.o ${OBJECTDIR}/mcc_generated_files/tmr1.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Utils.o ${OBJECTDIR}/keyboard.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/memory.o ${OBJECTDIR}/adc.o ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/i2c2.o.d ${OBJECTDIR}/mcc_generated_files/exceptions.o.d ${OBJECTDIR}/mcc_generated_files/uart1.o.d ${OBJECTDIR}/mcc_generated_files/rtcc.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/adc1.o.d ${OBJECTDIR}/mcc_generated_files/tmr1.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/Utils.o.d ${OBJECTDIR}/keyboard.o.d ${OBJECTDIR}/lcd.o.d ${OBJECTDIR}/memory.o.d ${OBJECTDIR}/adc.o.d ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/i2c2.o ${OBJECTDIR}/mcc_generated_files/exceptions.o ${OBJECTDIR}/mcc_generated_files/uart1.o ${OBJECTDIR}/mcc_generated_files/rtcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/adc1.o ${OBJECTDIR}/mcc_generated_files/tmr1.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Utils.o ${OBJECTDIR}/keyboard.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/memory.o ${OBJECTDIR}/adc.o ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o

# Source Files
SOURCEFILES=mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/i2c2.c mcc_generated_files/exceptions.c mcc_generated_files/uart1.c mcc_generated_files/rtcc.c mcc_generated_files/pin_manager.c mcc_generated_files/adc1.c mcc_generated_files/tmr1.c main.c Utils.c keyboard.c lcd.c memory.c adc.c mcc_generated_files/mccp1_compare.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PBLE02-firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MM0064GPM048
MP_LINKER_FILE_OPTION=
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/fae852d6a47a21a9c09c8448c41a73f34e527ba2 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/6bdf0a842356f66814d51c31983167bcf1d95369 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/c5e087b2ff07e3fa72cf04ab7ac959b15f774e1b .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/59e4f450781362cd2347f6a00f90c1e257ca4686 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/i2c2.o: mcc_generated_files/i2c2.c  .generated_files/flags/default/b8e02a1bf991c1446678352c3b5ae15ffa4442ed .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c2.o.d" -o ${OBJECTDIR}/mcc_generated_files/i2c2.o mcc_generated_files/i2c2.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/flags/default/14fda11c8bc96e5fb637a55fc2b5de6891ed850f .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/exceptions.o.d" -o ${OBJECTDIR}/mcc_generated_files/exceptions.o mcc_generated_files/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/uart1.o: mcc_generated_files/uart1.c  .generated_files/flags/default/52cade136cc25fe7cdc25ce9cb2175299c04281b .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart1.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart1.o mcc_generated_files/uart1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/rtcc.o: mcc_generated_files/rtcc.c  .generated_files/flags/default/70bac458a671c6ce0db6a8da3b44ee3010eb7759 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/rtcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/rtcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/rtcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/rtcc.o mcc_generated_files/rtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/72ea145162e501bbefb2b975ed015603c5180f3f .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/adc1.o: mcc_generated_files/adc1.c  .generated_files/flags/default/697aa86b5a9ebaa4679914e73f2b18258d76a6a0 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc1.o.d" -o ${OBJECTDIR}/mcc_generated_files/adc1.o mcc_generated_files/adc1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/tmr1.o: mcc_generated_files/tmr1.c  .generated_files/flags/default/699392a1934149c5ae2efec7c3bd27514cd1cfe1 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr1.o.d" -o ${OBJECTDIR}/mcc_generated_files/tmr1.o mcc_generated_files/tmr1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/cb179bf839e023a74233aa14e821d04565825de4 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/Utils.o: Utils.c  .generated_files/flags/default/f13c92c4fc618a27a2202637f61c6f03081258c0 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Utils.o.d 
	@${RM} ${OBJECTDIR}/Utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Utils.o.d" -o ${OBJECTDIR}/Utils.o Utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/keyboard.o: keyboard.c  .generated_files/flags/default/44680fcbeb255aacfadb38ec788afa077bb03601 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/keyboard.o.d 
	@${RM} ${OBJECTDIR}/keyboard.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/keyboard.o.d" -o ${OBJECTDIR}/keyboard.o keyboard.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/lcd.o: lcd.c  .generated_files/flags/default/c535a874f49905fad5d327d9647873dcb06ceda9 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/lcd.o.d" -o ${OBJECTDIR}/lcd.o lcd.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/memory.o: memory.c  .generated_files/flags/default/8b980dbfab5ad40d0bcd9ab0fb2f6845decbe48c .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/memory.o.d 
	@${RM} ${OBJECTDIR}/memory.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/memory.o.d" -o ${OBJECTDIR}/memory.o memory.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/flags/default/c784f02bae913a2e6445f576a03d79830f26ed6 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/adc.o.d" -o ${OBJECTDIR}/adc.o adc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/mccp1_compare.o: mcc_generated_files/mccp1_compare.c  .generated_files/flags/default/f554c215b1261fe30a636d273521cbde8475a77d .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mccp1_compare.o.d" -o ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o mcc_generated_files/mccp1_compare.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/4b301b228c8e663815026215a38f46403baf893 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/7ba2a0d0b9a193f039de4ac1ee34642f8aff70ab .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/4d6baabcef45f1d39d6f7df031ccc49cfd16a460 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/4bc8f70a5b7bf2240a73795d2519f57ffe91c687 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/i2c2.o: mcc_generated_files/i2c2.c  .generated_files/flags/default/799b6f9aa05bf499b2bbd4d9c101d73b91009a7b .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c2.o.d" -o ${OBJECTDIR}/mcc_generated_files/i2c2.o mcc_generated_files/i2c2.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/flags/default/c7533bfc00533ddbed69985ebf666b110fa1c6a2 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/exceptions.o.d" -o ${OBJECTDIR}/mcc_generated_files/exceptions.o mcc_generated_files/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/uart1.o: mcc_generated_files/uart1.c  .generated_files/flags/default/12a0cd1b6a9adee56e08bb4a3c00260dc9652c9a .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart1.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart1.o mcc_generated_files/uart1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/rtcc.o: mcc_generated_files/rtcc.c  .generated_files/flags/default/5770e02fafa967fd991938491f09d651c38a7d8b .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/rtcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/rtcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/rtcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/rtcc.o mcc_generated_files/rtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/65f5c28e292ddc7c11d495fc1ac075dbd16290d2 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/adc1.o: mcc_generated_files/adc1.c  .generated_files/flags/default/3211edb12c5d789c892f75e57647e0cc458f892b .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc1.o.d" -o ${OBJECTDIR}/mcc_generated_files/adc1.o mcc_generated_files/adc1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/tmr1.o: mcc_generated_files/tmr1.c  .generated_files/flags/default/bf38603756388bb10978492a4582c1a94ef297f5 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr1.o.d" -o ${OBJECTDIR}/mcc_generated_files/tmr1.o mcc_generated_files/tmr1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/226055037090bcc7b92bdc883c7a55a9dd5dce0d .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/Utils.o: Utils.c  .generated_files/flags/default/19919b58277eac0632df71ffe78652aca19ddb3 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Utils.o.d 
	@${RM} ${OBJECTDIR}/Utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Utils.o.d" -o ${OBJECTDIR}/Utils.o Utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/keyboard.o: keyboard.c  .generated_files/flags/default/1b4d1e8843d95c03c402bc9bbf8048169934e951 .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/keyboard.o.d 
	@${RM} ${OBJECTDIR}/keyboard.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/keyboard.o.d" -o ${OBJECTDIR}/keyboard.o keyboard.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/lcd.o: lcd.c  .generated_files/flags/default/a6e92083ab9b411db86b128274af199bc03a69da .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/lcd.o.d" -o ${OBJECTDIR}/lcd.o lcd.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/memory.o: memory.c  .generated_files/flags/default/6e86594d5675cdabfa779de119b7a58c19fd53be .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/memory.o.d 
	@${RM} ${OBJECTDIR}/memory.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/memory.o.d" -o ${OBJECTDIR}/memory.o memory.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/flags/default/47da4d3c5cd74dcedc7928ae9b9c3f399b9b7e0b .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/adc.o.d" -o ${OBJECTDIR}/adc.o adc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/mcc_generated_files/mccp1_compare.o: mcc_generated_files/mccp1_compare.c  .generated_files/flags/default/7e0524357a7811bd11993e1846d26b4f8616bd3b .generated_files/flags/default/d55f73a18bf11a00a687ff00baaa9b44bb96546
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mccp1_compare.o.d" -o ${OBJECTDIR}/mcc_generated_files/mccp1_compare.o mcc_generated_files/mccp1_compare.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PBLE02-firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/PBLE02-firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC016FF -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/PBLE02-firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/PBLE02-firmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/PBLE02-firmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
