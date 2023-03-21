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
FINAL_IMAGE=${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../../Downloads/proj2/main.c ../../Downloads/proj2/avr.c ../../Downloads/proj2/lcd.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1917044881/main.o ${OBJECTDIR}/_ext/1917044881/avr.o ${OBJECTDIR}/_ext/1917044881/lcd.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1917044881/main.o.d ${OBJECTDIR}/_ext/1917044881/avr.o.d ${OBJECTDIR}/_ext/1917044881/lcd.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1917044881/main.o ${OBJECTDIR}/_ext/1917044881/avr.o ${OBJECTDIR}/_ext/1917044881/lcd.o

# Source Files
SOURCEFILES=../../Downloads/proj2/main.c ../../Downloads/proj2/avr.c ../../Downloads/proj2/lcd.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1917044881/main.o: ../../Downloads/proj2/main.c  .generated_files/flags/default/22466e90fdbae3e87223feb8d187469c2980d370 .generated_files/flags/default/908078bc4f9544b0400ae29e2479debacd62a27e
	@${MKDIR} "${OBJECTDIR}/_ext/1917044881" 
	@${RM} ${OBJECTDIR}/_ext/1917044881/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1917044881/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1917044881/main.o.d" -MT "${OBJECTDIR}/_ext/1917044881/main.o.d" -MT ${OBJECTDIR}/_ext/1917044881/main.o -o ${OBJECTDIR}/_ext/1917044881/main.o ../../Downloads/proj2/main.c 
	
${OBJECTDIR}/_ext/1917044881/avr.o: ../../Downloads/proj2/avr.c  .generated_files/flags/default/3e57491280e239d0f243d63f49823c3dd5da19fd .generated_files/flags/default/908078bc4f9544b0400ae29e2479debacd62a27e
	@${MKDIR} "${OBJECTDIR}/_ext/1917044881" 
	@${RM} ${OBJECTDIR}/_ext/1917044881/avr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1917044881/avr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1917044881/avr.o.d" -MT "${OBJECTDIR}/_ext/1917044881/avr.o.d" -MT ${OBJECTDIR}/_ext/1917044881/avr.o -o ${OBJECTDIR}/_ext/1917044881/avr.o ../../Downloads/proj2/avr.c 
	
${OBJECTDIR}/_ext/1917044881/lcd.o: ../../Downloads/proj2/lcd.c  .generated_files/flags/default/e1e44bacbf2359630dee7729e33080cedf8abbc4 .generated_files/flags/default/908078bc4f9544b0400ae29e2479debacd62a27e
	@${MKDIR} "${OBJECTDIR}/_ext/1917044881" 
	@${RM} ${OBJECTDIR}/_ext/1917044881/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1917044881/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1917044881/lcd.o.d" -MT "${OBJECTDIR}/_ext/1917044881/lcd.o.d" -MT ${OBJECTDIR}/_ext/1917044881/lcd.o -o ${OBJECTDIR}/_ext/1917044881/lcd.o ../../Downloads/proj2/lcd.c 
	
else
${OBJECTDIR}/_ext/1917044881/main.o: ../../Downloads/proj2/main.c  .generated_files/flags/default/5ad2ef749c560c9d0c620ed757fd5c36d926b896 .generated_files/flags/default/908078bc4f9544b0400ae29e2479debacd62a27e
	@${MKDIR} "${OBJECTDIR}/_ext/1917044881" 
	@${RM} ${OBJECTDIR}/_ext/1917044881/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1917044881/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1917044881/main.o.d" -MT "${OBJECTDIR}/_ext/1917044881/main.o.d" -MT ${OBJECTDIR}/_ext/1917044881/main.o -o ${OBJECTDIR}/_ext/1917044881/main.o ../../Downloads/proj2/main.c 
	
${OBJECTDIR}/_ext/1917044881/avr.o: ../../Downloads/proj2/avr.c  .generated_files/flags/default/cf23a5c715421b308d87a10ca790880081a3c0ea .generated_files/flags/default/908078bc4f9544b0400ae29e2479debacd62a27e
	@${MKDIR} "${OBJECTDIR}/_ext/1917044881" 
	@${RM} ${OBJECTDIR}/_ext/1917044881/avr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1917044881/avr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1917044881/avr.o.d" -MT "${OBJECTDIR}/_ext/1917044881/avr.o.d" -MT ${OBJECTDIR}/_ext/1917044881/avr.o -o ${OBJECTDIR}/_ext/1917044881/avr.o ../../Downloads/proj2/avr.c 
	
${OBJECTDIR}/_ext/1917044881/lcd.o: ../../Downloads/proj2/lcd.c  .generated_files/flags/default/494a69ecb5993e0c741b02587f83f73e50d0b1b6 .generated_files/flags/default/908078bc4f9544b0400ae29e2479debacd62a27e
	@${MKDIR} "${OBJECTDIR}/_ext/1917044881" 
	@${RM} ${OBJECTDIR}/_ext/1917044881/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1917044881/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1917044881/lcd.o.d" -MT "${OBJECTDIR}/_ext/1917044881/lcd.o.d" -MT ${OBJECTDIR}/_ext/1917044881/lcd.o -o ${OBJECTDIR}/_ext/1917044881/lcd.o ../../Downloads/proj2/lcd.c 
	
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
${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../Downloads/proj2/main.c
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../Downloads/proj2/main.c
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/Project2Fin.X.${IMAGE_TYPE}.hex"
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
