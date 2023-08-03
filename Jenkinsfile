pipeline {
    agent {
        label 'sniper'
    }
    parameters {
        booleanParam(defaultValue: true, description: 'Build Program', name: 'BUILD')
        booleanParam(defaultValue: false, description: 'Build & Run Tests', name: 'TESTS')
        booleanParam(defaultValue: true, description: 'Remove artifacts', name: 'CLEAN')
    }
    stages {
        stage('Pull') {
            steps {
                git branch: 'main', url: 'https://github.com/demqa/QuadraticEquation.git'
            }
        }
        stage('Tests') {
            when {
                expression {
                    return params.TESTS
                }
            }

            steps {
                echo 'Running tests...'
                sh 'make debug'
                sh './debug'
            }
        }
        stage('Build') {
            when {
                expression {
                    return params.BUILD
                }
            }

            steps {
                echo 'Building...'
                sh 'make'
            }
        }
        stage('Clean') {
            when {
                expression {
                    return params.CLEAN
                }
            }

            steps {
                sh 'make clean'
                sh 'ls'
            }
        }
    }
}
