
#pragma once

#include <stdio.h>

#include "GLES2/gl2.h"
#include "EGL/egl.h"
#include "EGL/eglext.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>


typedef struct
{
    Window window;  // backing window for pi, render window for mesa
    Display *display;
    Cursor invisible_cursor;
    int mouse_is_relative;
    int ignore_next_motion_event;
    int accumulative_mouse_motion_x;
    int accumulative_mouse_motion_y;
    Atom WM_PROTOCOLS;
    Atom WM_DELETE_WINDOW;
} X11_EVENT_STATE_T;

void x11_event_init(Display *display, Window window);
void set_mouse_relative();
void set_mouse_absolute();

void pg_next_event();

typedef void (*KeyPressHandler)(unsigned char, int mods, int keysym);
typedef void (*KeyReleaseHandler)(unsigned char, int keysym);
typedef void (*MotionHandler)(int diff_x, int diff_y);
typedef void (*MousePressHandler)(int button, int mods);
typedef void (*MouseReleaseHandler)(int button, int mods);
typedef void (*WindowCloseHandler)();

void set_key_press_handler(KeyPressHandler key_press_handler);
void set_key_release_handler(KeyReleaseHandler key_release_handler);
void set_motion_handler(MotionHandler motion_handler);
void set_mouse_press_handler(MousePressHandler mouse_press_handler);
void set_mouse_release_handler(MouseReleaseHandler mouse_release_handler);
void set_window_close_handler(WindowCloseHandler window_close_handler);

void get_x11_accumulative_mouse_motion(int *x, int *y);

void _pg_fatal(char *format, ...);
