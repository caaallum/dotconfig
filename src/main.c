#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include "../config.h"
#include "config.h"
#include "ini.h"

int main(int argc, char **argv) {
    static gboolean display_version = FALSE;
    static gchar *config_dir = NULL;
    static gboolean uninstall = FALSE;
    GError *error = NULL;
    GOptionContext *option_context;
    static GOptionEntry entries[] = {
        { "version", 'V', 0, G_OPTION_ARG_NONE, &display_version,
          "Display version information", NULL },
        { "config-dir", 'C', 0, G_OPTION_ARG_STRING, &config_dir,
          "Set directory for config files", NULL },
        { "uninstall", 'u', 0, G_OPTION_ARG_NONE, &uninstall,
          "Uninstalling config files", NULL },
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

    config_t *config = NULL;

    if (config_dir) {
        config = ini_load_config(config_dir);
    } else {
        config = ini_load_config(NULL);
    }

    config_free(config);
    return 0;
}
