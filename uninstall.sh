#!/bin/bash

PATH_INSTALLING="/usr/local/bin"
PATH_INSTALLING_ICON="/usr/local/share/icons"
PATH_INSTALLING_DESKTOP="/usr/share/applications"
NAME_PROGRAM="Workerin"

rm ${PATH_INSTALLING}/${NAME_PROGRAM}
rm ${PATH_INSTALLING_ICON}/${NAME_PROGRAM}.png
rm ${PATH_INSTALLING_DESKTOP}/${NAME_PROGRAM}.desktop

if [ -f ${PATH_INSTALLING}/${NAME_PROGRAM} ] || [ -f ${PATH_INSTALLING_ICON}/${NAME_PROGRAM}.png ] || [ -f ${PATH_INSTALLING_DESKTOP}/${NAME_PROGRAM}.desktop ]
then
    echo "The program not will be uninstalling!"
    exit 1
fi

echo "Uninstalling successful!"

exit 0
