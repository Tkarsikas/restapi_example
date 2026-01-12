include(C:/GIT_Repositoryt/restapi_example/frontend/restapi_example/build/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/restapi_example-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/GIT_Repositoryt/restapi_example/frontend/restapi_example/build/restapi_example.exe
    GENERATE_QT_CONF
)
