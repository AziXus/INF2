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
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/8c3c5305/Carte.o \
	${OBJECTDIR}/_ext/8c3c5305/Joueur.o \
	${OBJECTDIR}/_ext/8c3c5305/Partie.o \
	${OBJECTDIR}/_ext/8c3c5305/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wall -Wconversion -Wextra -pedantic
CXXFLAGS=-Wall -Wconversion -Wextra -pedantic

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/labo3_pointeur.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/labo3_pointeur.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/labo3_pointeur ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/8c3c5305/Carte.o: ../Labo_3/Carte.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/8c3c5305
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/8c3c5305/Carte.o ../Labo_3/Carte.cpp

${OBJECTDIR}/_ext/8c3c5305/Joueur.o: ../Labo_3/Joueur.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/8c3c5305
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/8c3c5305/Joueur.o ../Labo_3/Joueur.cpp

${OBJECTDIR}/_ext/8c3c5305/Partie.o: ../Labo_3/Partie.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/8c3c5305
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/8c3c5305/Partie.o ../Labo_3/Partie.cpp

${OBJECTDIR}/_ext/8c3c5305/main.o: ../Labo_3/main.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/8c3c5305
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/8c3c5305/main.o ../Labo_3/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
