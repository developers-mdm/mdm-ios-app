Pod::Spec.new do |s|
  s.name                    = 'MDMCore'
  s.version                 = '3.9.14'
  s.summary                 = 'Hands MDM'
  s.homepage                = 'https://hands.com.br/'

  s.author                  = { 'Name' => 'robson.moreira@hands.com.br' }
  s.license                 = { :type => 'Apache-2.0', :file => 'MDMCore/LICENSE' }

  s.platform                = :ios
  s.source                  = { :http => 'https://nexus.hands.com.br/repository/maven-external/br/com/hands/mdm/libs/ios/mdm-core/' + s.version.to_s + '/mdm-core-' + s.version.to_s + '.zip' }

  s.ios.deployment_target   = '10.0'
  s.ios.vendored_frameworks = 'MDMCore/MDMCore.xcframework'
end
