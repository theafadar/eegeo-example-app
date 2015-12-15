// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#import <UIKit/UIKit.h>

#include "MenuView.h"
#include "SearchMenuViewIncludes.h"

@class SearchMenuView;

@interface SearchMenuView : MenuView<UITextFieldDelegate>
{
    ExampleApp::SearchMenu::View::SearchMenuViewInterop* m_pSearchMenuInterop;

    bool m_keyboardActive;
    bool m_returnPressed;
    bool m_currentSearchIsCategory;

    float m_searchBoxContainerX;
    float m_searchBoxContainerY;
    float m_searchBoxContainerWidth;
    float m_searchBoxContainerHeight;
}

- (void)initialiseViews:(size_t)numberOfSections numberOfCells:(size_t)numberOfCells;

- (ExampleApp::SearchMenu::View::SearchMenuViewInterop*) getSearchMenuInterop;

- (void) enableEdit;

- (void) disableEdit;

- (void) removeSeachKeyboard;

- (void) setEditText :(NSString*)searchText
                     :(bool)isCategory;

- (void) collapseAll;

- (void) onRowsAdded;

- (void) onRowsDeleted;

@property (nonatomic, retain) UITextField* pSearchEditBox;
@property (nonatomic, retain) UIView* pSearchEditBoxContainer;

@end
