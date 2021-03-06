#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=gcc
CXX=gcc
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/LIB/db_mysql_threded.o \
	${OBJECTDIR}/LIB/debug.o \
	${OBJECTDIR}/LIB/makeQueryToDb.o \
	${OBJECTDIR}/LIB/mysql_creat_var_val_struct.o \
	${OBJECTDIR}/LIB/mysql_select.o \
	${OBJECTDIR}/LIB/mysql_select_multy.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/newsimpletest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mysqlresult2varval

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mysqlresult2varval: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mysqlresult2varval ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/LIB/db_mysql_threded.o: LIB/db_mysql_threded.c
	${MKDIR} -p ${OBJECTDIR}/LIB
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/db_mysql_threded.o LIB/db_mysql_threded.c

${OBJECTDIR}/LIB/debug.o: LIB/debug.c
	${MKDIR} -p ${OBJECTDIR}/LIB
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/debug.o LIB/debug.c

${OBJECTDIR}/LIB/makeQueryToDb.o: LIB/makeQueryToDb.c
	${MKDIR} -p ${OBJECTDIR}/LIB
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/makeQueryToDb.o LIB/makeQueryToDb.c

${OBJECTDIR}/LIB/mysql_creat_var_val_struct.o: LIB/mysql_creat_var_val_struct.c
	${MKDIR} -p ${OBJECTDIR}/LIB
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/mysql_creat_var_val_struct.o LIB/mysql_creat_var_val_struct.c

${OBJECTDIR}/LIB/mysql_select.o: LIB/mysql_select.c
	${MKDIR} -p ${OBJECTDIR}/LIB
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/mysql_select.o LIB/mysql_select.c

${OBJECTDIR}/LIB/mysql_select_multy.o: LIB/mysql_select_multy.c
	${MKDIR} -p ${OBJECTDIR}/LIB
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/mysql_select_multy.o LIB/mysql_select_multy.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.c


${OBJECTDIR}/LIB/db_mysql_threded_nomain.o: ${OBJECTDIR}/LIB/db_mysql_threded.o LIB/db_mysql_threded.c 
	${MKDIR} -p ${OBJECTDIR}/LIB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LIB/db_mysql_threded.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/db_mysql_threded_nomain.o LIB/db_mysql_threded.c;\
	else  \
	    ${CP} ${OBJECTDIR}/LIB/db_mysql_threded.o ${OBJECTDIR}/LIB/db_mysql_threded_nomain.o;\
	fi

${OBJECTDIR}/LIB/debug_nomain.o: ${OBJECTDIR}/LIB/debug.o LIB/debug.c 
	${MKDIR} -p ${OBJECTDIR}/LIB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LIB/debug.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/debug_nomain.o LIB/debug.c;\
	else  \
	    ${CP} ${OBJECTDIR}/LIB/debug.o ${OBJECTDIR}/LIB/debug_nomain.o;\
	fi

${OBJECTDIR}/LIB/makeQueryToDb_nomain.o: ${OBJECTDIR}/LIB/makeQueryToDb.o LIB/makeQueryToDb.c 
	${MKDIR} -p ${OBJECTDIR}/LIB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LIB/makeQueryToDb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/makeQueryToDb_nomain.o LIB/makeQueryToDb.c;\
	else  \
	    ${CP} ${OBJECTDIR}/LIB/makeQueryToDb.o ${OBJECTDIR}/LIB/makeQueryToDb_nomain.o;\
	fi

${OBJECTDIR}/LIB/mysql_creat_var_val_struct_nomain.o: ${OBJECTDIR}/LIB/mysql_creat_var_val_struct.o LIB/mysql_creat_var_val_struct.c 
	${MKDIR} -p ${OBJECTDIR}/LIB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LIB/mysql_creat_var_val_struct.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/mysql_creat_var_val_struct_nomain.o LIB/mysql_creat_var_val_struct.c;\
	else  \
	    ${CP} ${OBJECTDIR}/LIB/mysql_creat_var_val_struct.o ${OBJECTDIR}/LIB/mysql_creat_var_val_struct_nomain.o;\
	fi

${OBJECTDIR}/LIB/mysql_select_nomain.o: ${OBJECTDIR}/LIB/mysql_select.o LIB/mysql_select.c 
	${MKDIR} -p ${OBJECTDIR}/LIB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LIB/mysql_select.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/mysql_select_nomain.o LIB/mysql_select.c;\
	else  \
	    ${CP} ${OBJECTDIR}/LIB/mysql_select.o ${OBJECTDIR}/LIB/mysql_select_nomain.o;\
	fi

${OBJECTDIR}/LIB/mysql_select_multy_nomain.o: ${OBJECTDIR}/LIB/mysql_select_multy.o LIB/mysql_select_multy.c 
	${MKDIR} -p ${OBJECTDIR}/LIB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LIB/mysql_select_multy.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LIB/mysql_select_multy_nomain.o LIB/mysql_select_multy.c;\
	else  \
	    ${CP} ${OBJECTDIR}/LIB/mysql_select_multy.o ${OBJECTDIR}/LIB/mysql_select_multy_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
