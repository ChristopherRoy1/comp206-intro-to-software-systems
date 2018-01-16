#!/bin/bash
#


#Function to test if the directory 
testExistance(){
	if ( !( test -d "$checkdir") ); then
		mkdir $checkdir
	fi
}

#Function that checks if the project directory exists, and creates it if it doesn't
createPDirectory(){
	if [ -z "$name" ]; then
		echo "usage: $0 name"
	 	exit
	elif ( test -d "$name" ); then
		echo "This project name has already been used."
		exit
	else
		mkdir "$name"
		cd "$name"
		mkdir "archive" "backup" "docs" "assests" "database" "source"
	fi
}

#Function that generates the backup script that will be in the source folder
genBackupScript(){
	echo "#!/bin/bash" > backup.sh
	echo "cp *.c *.h  ../backup" >> backup.sh
	chmod 755 backup.sh 
}

name="$1"

cd ~

checkdir="project"

testExistance

cd project

checkdir="cs206"

testExistance

cd cs206

createPDirectory

cd source

genBackupScript

echo "Your project directories have been created."

