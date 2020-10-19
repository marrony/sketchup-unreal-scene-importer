#include "SketchupSceneFactory.h"
#include "Misc/MessageDialog.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"
#include "Curves/CurveBase.h"
#include "Curves/CurveFloat.h"
#include "Factories/ReimportCurveFactory.h"
#include "Factories/ReimportCurveTableFactory.h"
#include "Factories/ReimportDataTableFactory.h"
#include "EditorFramework/AssetImportData.h"
#include "Curves/CurveLinearColor.h"
#include "Curves/CurveVector.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "Editor.h"

//#include "Interfaces/IMainFrameModule.h"
//#include "SCSVImportOptions.h"
//#include "DataTableEditorUtils.h"
//#include "JsonObjectConverter.h"

DEFINE_LOG_CATEGORY(LogSketchupSceneFactory);

#define LOCTEXT_NAMESPACE "SketchupSceneFactory"

USketchupSceneFactory::USketchupSceneFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bCreateNew = false;
    bEditAfterNew = false;
    SupportedClass = UStaticMesh::StaticClass();

    bEditorImport = true;
    bText = true;

    // Give this factory a lower than normal import priority, as CSV and JSON can be commonly used and we'd like to give the other import factories a shot first
    //--ImportPriority;

    Formats.Add(TEXT("scene;Sketchup Scene"));
}

FText USketchupSceneFactory::GetDisplayName() const
{
    return LOCTEXT("SketchupSceneImportFactoryDescription", "My Scene");
}

bool USketchupSceneFactory::DoesSupportClass(UClass * Class)
{
    return Class == UStaticMesh::StaticClass();
}

bool USketchupSceneFactory::FactoryCanImport(const FString& Filename)
{
    const FString Extension = FPaths::GetExtension(Filename);

    if (Extension == TEXT("scene"))
    {
        return true;
    }
    return false;
}

UObject* USketchupSceneFactory::FactoryCreateText(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const TCHAR*& Buffer, const TCHAR* BufferEnd, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
    GEditor->GetEditorSubsystem<UImportSubsystem>()->BroadcastAssetPreImport(this, InClass, InParent, InName, Type);

    bOutOperationCanceled = false;

    UObject* NewAsset = nullptr;

    GEditor->GetEditorSubsystem<UImportSubsystem>()->BroadcastAssetPostImport(this, NewAsset);

    return NewAsset;
}

#undef LOCTEXT_NAMESPACE

