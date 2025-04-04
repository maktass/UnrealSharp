#include "CSSoftClassPropertyGenerator.h"
#include "TypeGenerator/Register/MetaData/CSObjectMetaData.h"

struct FCSObjectMetaData;

FProperty* UCSSoftClassPropertyGenerator::CreateProperty(UField* Outer, const FCSPropertyMetaData& PropertyMetaData)
{
	FSoftClassProperty* NewProperty = static_cast<FSoftClassProperty*>(Super::CreateProperty(Outer, PropertyMetaData));
	TSharedPtr<FCSObjectMetaData> ObjectMetaData = PropertyMetaData.GetTypeMetaData<FCSObjectMetaData>();
	UClass* Class = ObjectMetaData->InnerType.GetOwningClass();
	
	NewProperty->PropertyClass = UClass::StaticClass();
	NewProperty->SetMetaClass(Class);
	return NewProperty;
}

TSharedPtr<FCSUnrealType> UCSSoftClassPropertyGenerator::CreateTypeMetaData(
	ECSPropertyType PropertyType)
{
	return MakeShared<FCSObjectMetaData>();
}
