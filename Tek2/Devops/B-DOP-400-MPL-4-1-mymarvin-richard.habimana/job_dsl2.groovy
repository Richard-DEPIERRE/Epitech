job('$DISPLAY_NAME') {
    properties {
        githubProjectUrl('$GITHUB_NAME')
    }
    steps {
        shell('make fclean')
        shell('make')
        shell('make test')
        shell('make clean')
    }
    wrappers {
        preBuildCleanup {
            includePattern('**/target/**')
            deleteDirectories()
            cleanupParameter('CLEANUP')
        }
    }
}