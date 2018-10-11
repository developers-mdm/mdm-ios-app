#!/bin/bash

rm -rf com-hands-mdm-mobile-ios-specs-beta/ com-hands-mdm-mobile-ios-specs-alfa/
rm -rf ~/Library/Caches/CocoaPods
rm -rf Pods
rm -rf MDM\ iOS\ Example.xcworkspace
rm -rf Podfile.lock
rm -rf ~/Library/Developer/Xcode/DerivedData/*
pod deintegrate
pod setup
pod install
open MDM\ iOS\ Example.xcworkspace
