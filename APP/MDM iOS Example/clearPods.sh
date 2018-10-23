#!/bin/bash

rm -rf ~/Library/Caches/CocoaPods
rm -rf Pods
rm -rf MDM\ iOS\ Example.xcworkspace
rm -rf Podfile.lock
rm -rf ~/Library/Developer/Xcode/DerivedData/*
pod deintegrate
pod setup
pod install
open MDM\ iOS\ Example.xcworkspace
