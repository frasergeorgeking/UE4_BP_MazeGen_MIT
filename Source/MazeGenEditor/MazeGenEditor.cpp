#include "MazeGenEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

IMPLEMENT_GAME_MODULE(FMazeGenEditorModule, MazeGenEditor);
DEFINE_LOG_CATEGORY(MazeGenEditor)
#define LOCTEXT_NAMESPACE "MazeGenEditor"

void FMazeGenEditorModule::StartupModule()
{
    UE_LOG(MazeGenEditor, Warning, TEXT("MazeGenEditor: Log Started"));
}

void FMazeGenEditorModule::ShutdownModule()
{
    UE_LOG(MazeGenEditor, Warning, TEXT("MazeGenEditor: Log Ended"));
}

#undef LOCTEXT_NAMESPACE