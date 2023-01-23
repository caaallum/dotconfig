#include <stdio.h>
#include <ini.h>
#include <glib.h>
#include <stdlib.h>
#include "../config.h"
#include "config.h"

static int handler(void *user_data, const char *section, const char *name, const char *value) {
    config_t *config = user_data;
    if (strcmp(section, "settings") == 0) {
        if (strcmp(name, "method") == 0) {
            config_set_method(config, value);
        }
    } else {
    }

    return 1;
}

int main(int argc, char **argv) {
    static gboolean display_version = FALSE;
    static gchar *config_dir = NULL;
    GError *error = NULL;
    GOptionContext *option_context;
    static GOptionEntry entries[] = {
        { "version", 'V', 0, G_OPTION_ARG_NONE, &display_version,
          "Display version information", NULL },
        { "config-dir", 'C', 0, G_OPTION_ARG_STRING, &config_dir,
          "Set directory for config files", NULL },
        { NULL, 0, 0, 0, NULL, NULL, NULL }
    };

    option_context = g_option_context_new(NULL);
    g_option_context_add_main_entries(option_context, entries, NULL);

    if (!g_option_context_parse(option_context, &argc, &argv, &error)) {
        g_print("%s\n", error->message);
        return EXIT_SUCCESS;
    }
    g_option_context_free(option_context);

    if (display_version) {
        g_print("%s %s\n", argv[0], VERSION);
        return EXIT_SUCCESS;
    }

    if (argc > 1) {
        if (strcmp(argv[1], "install") == 0) {
            if (argc > 2) {
                g_print("Installing: ");
                for (int i = 2; i < argc; i++) {
                    g_print("%s ", argv[i]);
                }
                g_print("\n");
            } else {
                g_print("Installing all\n");
            }
        } else if (strcmp(argv[1], "uninstall") == 0) {
            g_print("Uninstalling: ");
            for (int i = 2; i < argc; i++) {
                g_print("%s ", argv[i]);
            }
            g_print("\n");
        } else {
            g_print("Installing all");
        }
    }

    config_t *config = config_new();
    if (ini_parse("dotconfig", handler, config) < 0) {
        printf("no dotconfig file found\n");
        return 1;
    }

    printf("Method: %s\n", config->method);

    config_free(config);
    return 0;
}
