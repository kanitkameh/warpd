//GENERATED BY gen_assets.py

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "cfg.h"

static int kvp(char *line, char **key, char **val) {
  *key = NULL;
  *val = NULL;
  
  for(;*line != '\0';line++) {
    if(*line != ' ' && !*key)
      *key = line;
    
    if(*line == ':' && !*val) {
      *line++ = '\0';
      for(;isspace(*line);line++);
      *val = line;
    }
  }
  
  if(*(line - 1) == '\n')
    *(line - 1) = '\0';
  
  if(!(*val && *key))
    return -1;
  
  return 0;
}

struct cfg* parse_cfg(const char *fname) {
    char *line = NULL;
    size_t n = 0, ln = 0;
    struct cfg *cfg = malloc(sizeof(struct cfg));

    cfg->hint_activation_key = "M-z";
    cfg->grid_activation_key = "M-x";
    cfg->discrete_activation_key = "M-c";
    cfg->movement_increment = 20;
    cfg->buttons = "m,comma,period,x,c";
    cfg->exit = "Escape";
    cfg->double_click_timeout = 300;
    cfg->drag_key = "v";
    cfg->grid_nr = 2;
    cfg->grid_nc = 2;
    cfg->grid_up = "w";
    cfg->grid_left = "a";
    cfg->grid_down = "s";
    cfg->grid_right = "d";
    cfg->grid_keys = "u,i,j,k";
    cfg->grid_color = "#ff0000";
    cfg->grid_mouse_color = "#00ff00";
    cfg->grid_pointer_size = 20;
    cfg->grid_line_width = 5;
    cfg->hint_width = 40;
    cfg->hint_height = 30;
    cfg->hint_up = "k";
    cfg->hint_left = "h";
    cfg->hint_down = "j";
    cfg->hint_right = "l";
    cfg->hint_bgcolor = "#00ff00";
    cfg->hint_fgcolor = "#000000";
    cfg->hint_characters = "asdfghjkl;'zxcvbm,./";
    cfg->hint_opacity = 100;
    cfg->discrete_left = "h";
    cfg->discrete_down = "j";
    cfg->discrete_up = "k";
    cfg->discrete_right = "l";
    cfg->discrete_color = "#00ff00";
    cfg->discrete_size = 20;
    cfg->discrete_home = "S-h";
    cfg->discrete_middle = "S-m";
    cfg->discrete_last = "S-l";
    cfg->discrete_beginning = "S-6";
    cfg->discrete_end = "S-4";
    cfg->scroll_fling_timeout = 150;
    cfg->scroll_fling_velocity = 40;
    cfg->scroll_fling_acceleration = 10;
    cfg->scroll_fling_deceleration = 30;
    cfg->scroll_velocity = 10;
    cfg->scroll_acceleration = 30;

    FILE *fp = fopen(fname, "r");
    if(!fp) return cfg; //Return defaults if no config file xists..
    while(getline(&line, &n, fp) != -1) {
        ln++;
        char *key, *val;
        if(kvp(line, &key, &val)) {
            fprintf(stderr, "Invalid entry in %s at line %lu.\n", fname, ln);
            exit(1);
        }

        if(!strcmp(key, "hint_activation_key"))
            cfg->hint_activation_key = strdup(val);
        else if(!strcmp(key, "grid_activation_key"))
            cfg->grid_activation_key = strdup(val);
        else if(!strcmp(key, "discrete_activation_key"))
            cfg->discrete_activation_key = strdup(val);
        else if(!strcmp(key, "movement_increment"))
            cfg->movement_increment = atoi(val);
        else if(!strcmp(key, "buttons"))
            cfg->buttons = strdup(val);
        else if(!strcmp(key, "exit"))
            cfg->exit = strdup(val);
        else if(!strcmp(key, "double_click_timeout"))
            cfg->double_click_timeout = atoi(val);
        else if(!strcmp(key, "drag_key"))
            cfg->drag_key = strdup(val);
        else if(!strcmp(key, "grid_nr"))
            cfg->grid_nr = atoi(val);
        else if(!strcmp(key, "grid_nc"))
            cfg->grid_nc = atoi(val);
        else if(!strcmp(key, "grid_up"))
            cfg->grid_up = strdup(val);
        else if(!strcmp(key, "grid_left"))
            cfg->grid_left = strdup(val);
        else if(!strcmp(key, "grid_down"))
            cfg->grid_down = strdup(val);
        else if(!strcmp(key, "grid_right"))
            cfg->grid_right = strdup(val);
        else if(!strcmp(key, "grid_keys"))
            cfg->grid_keys = strdup(val);
        else if(!strcmp(key, "grid_color"))
            cfg->grid_color = strdup(val);
        else if(!strcmp(key, "grid_mouse_color"))
            cfg->grid_mouse_color = strdup(val);
        else if(!strcmp(key, "grid_pointer_size"))
            cfg->grid_pointer_size = atoi(val);
        else if(!strcmp(key, "grid_line_width"))
            cfg->grid_line_width = atoi(val);
        else if(!strcmp(key, "hint_width"))
            cfg->hint_width = atoi(val);
        else if(!strcmp(key, "hint_height"))
            cfg->hint_height = atoi(val);
        else if(!strcmp(key, "hint_up"))
            cfg->hint_up = strdup(val);
        else if(!strcmp(key, "hint_left"))
            cfg->hint_left = strdup(val);
        else if(!strcmp(key, "hint_down"))
            cfg->hint_down = strdup(val);
        else if(!strcmp(key, "hint_right"))
            cfg->hint_right = strdup(val);
        else if(!strcmp(key, "hint_bgcolor"))
            cfg->hint_bgcolor = strdup(val);
        else if(!strcmp(key, "hint_fgcolor"))
            cfg->hint_fgcolor = strdup(val);
        else if(!strcmp(key, "hint_characters"))
            cfg->hint_characters = strdup(val);
        else if(!strcmp(key, "hint_opacity"))
            cfg->hint_opacity = atoi(val);
        else if(!strcmp(key, "discrete_left"))
            cfg->discrete_left = strdup(val);
        else if(!strcmp(key, "discrete_down"))
            cfg->discrete_down = strdup(val);
        else if(!strcmp(key, "discrete_up"))
            cfg->discrete_up = strdup(val);
        else if(!strcmp(key, "discrete_right"))
            cfg->discrete_right = strdup(val);
        else if(!strcmp(key, "discrete_color"))
            cfg->discrete_color = strdup(val);
        else if(!strcmp(key, "discrete_size"))
            cfg->discrete_size = atoi(val);
        else if(!strcmp(key, "discrete_home"))
            cfg->discrete_home = strdup(val);
        else if(!strcmp(key, "discrete_middle"))
            cfg->discrete_middle = strdup(val);
        else if(!strcmp(key, "discrete_last"))
            cfg->discrete_last = strdup(val);
        else if(!strcmp(key, "discrete_beginning"))
            cfg->discrete_beginning = strdup(val);
        else if(!strcmp(key, "discrete_end"))
            cfg->discrete_end = strdup(val);
        else if(!strcmp(key, "scroll_fling_timeout"))
            cfg->scroll_fling_timeout = atoi(val);
        else if(!strcmp(key, "scroll_fling_velocity"))
            cfg->scroll_fling_velocity = atoi(val);
        else if(!strcmp(key, "scroll_fling_acceleration"))
            cfg->scroll_fling_acceleration = atoi(val);
        else if(!strcmp(key, "scroll_fling_deceleration"))
            cfg->scroll_fling_deceleration = atoi(val);
        else if(!strcmp(key, "scroll_velocity"))
            cfg->scroll_velocity = atoi(val);
        else if(!strcmp(key, "scroll_acceleration"))
            cfg->scroll_acceleration = atoi(val);

        free(line);
        line = NULL;
        n = 0;
    }

    return cfg;
}
