// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SearchResultModel.h"

namespace ExampleApp
{
	namespace SearchResultMenu
	{
		class SearchResultAddedMessage
		{
			Search::SearchResultModel m_model;

		public:
			SearchResultAddedMessage(
			    const Search::SearchResultModel& model
			);

			const Search::SearchResultModel& Model() const;
		};
	}
}