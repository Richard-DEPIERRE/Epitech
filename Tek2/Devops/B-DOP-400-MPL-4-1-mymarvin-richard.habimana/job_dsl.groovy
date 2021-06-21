import jenkins.model.Jenkins;
import net.sf.json.JSONObject;

folder('Tools') {
    displayName('Tools')
    description('Folder for miscellaneous tools.')
}
job('Tools/clone-repository') {
    description('Git URL of the repository to clone')
    parameters{
        stringParam('GIT_REPOSITORY_URL', '', 'Git URL of the repository to clone')
    }
    steps {
        shell('git clone $GIT_REPOSITORY_URL')
    }
    wrappers {
        preBuildCleanup()
    }
}
job('Tools/SEED') {
    description('Git URL of the repository to clone')
    parameters{
        stringParam('GITHUB_NAME', '', 'GitHub repository owner/repo_name (e.g.: "EpitechIT31000/chocolatine")')
        stringParam('DISPLAY_NAME', '', 'Display name for the job')
    }
    steps {
        dsl{
            text('''
            job("$DISPLAY_NAME") {
                scm {
                    github("$GITHUB_NAME")
                }
                triggers {
                    scm('* * * * *')
                }
                steps {
                    shell('make fclean')
                    shell('make')
                    shell('make tests_run')
                    shell('make clean')
                }
                wrappers {
                    preBuildCleanup()
                }
            }
            '''.stripIndent())
        }
    }
}