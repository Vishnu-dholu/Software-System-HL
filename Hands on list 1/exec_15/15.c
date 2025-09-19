/*
  ===============================================================================================
  Name : 15.c
  Author : Vishnu Dholu
  Description : 15. Write a program to display the environmental variable of the user (use environ).
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>

extern char **environ;

int main(){
    char **env = environ;       // env is a pointer to the first element of that array

    printf("Environment variables:\n\n");
    while (*env) {
        printf("%s\n", *env);   // *env is a char*
        env++;
    }

    return 0;
}

/*
OUTPUT
XDG_CURRENT_DESKTOP=ubuntu:GNOME
MEMORY_PRESSURE_WATCH=/sys/fs/cgroup/user.slice/user-1000.slice/user@1000.service/session.slice/org.gnome.SettingsDaemon.MediaKeys.service/memory.pressure
VTE_VERSION=8000
WAYLAND_DISPLAY=wayland-0
GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/baca9ca2_55b3_48b0_b7a8_87966e31390c
GNOME_SETUP_DISPLAY=:1
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=vishnu-dholu
GNOME_TERMINAL_SERVICE=:1.170
DISPLAY=:0
SHLVL=1
GSM_SKIP_SSH_AGENT_WORKAROUND=true
QT_IM_MODULE=ibus
XDG_RUNTIME_DIR=/run/user/1000
DEBUGINFOD_URLS=https://debuginfod.ubuntu.com 
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/vishnu-dholu/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
GDMSESSION=ubuntu
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
OLDPWD=/home/vishnu-dholu/iiitb/sys_software/lab/Hands on list 1
_=./a.out

*/

// environ is a global variable exposed by the C runtime.
// char **environ;
// -> its an array of C-strings, each string in the form "KEY=VALUE"
// -> the array ends with a NULL pointer