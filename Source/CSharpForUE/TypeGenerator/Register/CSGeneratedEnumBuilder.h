﻿#pragma once

#include "CSGeneratedTypeBuilder.h"
#include "CSTypeRegistry.h"
#include "TypeGenerator/CSEnum.h"

class CSHARPFORUE_API FCSGeneratedEnumBuilder : public TCSGeneratedTypeBuilder<FEnumMetaData, UCSEnum>
{
	
public:
	
	FCSGeneratedEnumBuilder(const TSharedPtr<FEnumMetaData>& InTypeMetaData) : TCSGeneratedTypeBuilder(InTypeMetaData) { }

	// TCSGeneratedTypeBuilder interface implementation
	virtual void StartBuildingType() override;
	virtual void NewField(UCSEnum* OldField, UCSEnum* NewField) override;
	// End of implementation
};
