#include <stdio.h>
#include <stdlib.h>
#include <libssh/libssh.h>

int main()
{
    ssh_session session;
    session = ssh_new();

    if (session == NULL)
    {
        fprintf(stderr, "Error al crear la sesión SSH\n");
        return 1;
    }

    const char *username = "";
    const char *password = "";
    const char *server = "";

    ssh_options_set(session, SSH_OPTIONS_USER, username);
    ssh_options_set(session, SSH_OPTIONS_HOST, server);

    int rc = ssh_connect(session);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error al conectar al servidor SSH: %s\n", ssh_get_error(session));
        ssh_free(session);
        return 1;
    }

    rc = ssh_userauth_password(session, NULL, password);
    if (rc != SSH_AUTH_SUCCESS)
    {
        fprintf(stderr, "Error de autenticación: %s\n", ssh_get_error(session));
        ssh_disconnect(session);
        ssh_free(session);
        return 1;
    }

    printf("Banner del servidor SSH:\n%s\n", ssh_get_serverbanner(session));

    ssh_disconnect(session);
    ssh_free(session);

    return 0;
}
