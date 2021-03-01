while (1) {
    type prompt( );
    read command(command, parameters);

    if (for k( ) != 0) {
        waitpid(−1, &status, 0);
    } else {
        execve(command, parameters, 0);
    }
}
