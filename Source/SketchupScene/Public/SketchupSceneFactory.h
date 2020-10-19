#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Curves/RichCurve.h"
#include "Factories/Factory.h"
#include "Factories/ImportSettings.h"
#include "EditorReimportHandler.h"
#include "SketchupSceneFactory.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSketchupSceneFactory, Log, All);

UCLASS(hidecategories=Object)
class UNREALED_API USketchupSceneFactory : public UFactory
{
    GENERATED_UCLASS_BODY()

    virtual FText GetDisplayName() const override;
    virtual UObject* FactoryCreateText(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const TCHAR*& Buffer, const TCHAR* BufferEnd, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
    virtual bool DoesSupportClass(UClass * Class) override;
    virtual bool FactoryCanImport(const FString& Filename) override;
};
