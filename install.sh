#!/bin/bash

CPU_COUNT=`nproc --all`
PATH_INSTALLING="/usr/local/bin"
PATH_INSTALLING_ICON="/usr/local/share/icons"
PATH_INSTALLING_DESKTOP="/usr/share/applications"
NAME_PROGRAM="TermPaper"

mkdir build

cd build

echo "Start configuration"

cmake ..

echo "Start compilation"

make -j ${CPU_COUNT}

if [ ! -f ./bin/${NAME_PROGRAM} ]
then
    echo "The program will not be compilation!"
    exit 1
fi

echo "Installing..."

cp ./bin/${NAME_PROGRAM} ${PATH_INSTALLING}
cp ../install_files/${NAME_PROGRAM}.desktop ${PATH_INSTALLING_DESKTOP}

if [ ! -d ${PATH_INSTALLING_ICON} ]
then
    mkdir ${PATH_INSTALLING_ICON}
fi

cp ../install_files/${NAME_PROGRAM}.png ${PATH_INSTALLING_ICON}

if [ -f ${PATH_INSTALLING}/${NAME_PROGRAM} ]
then
    echo "Well done. Installing successful!"
else
    echo "The program will not be installing!"
    exit 1
fi

exit 0
