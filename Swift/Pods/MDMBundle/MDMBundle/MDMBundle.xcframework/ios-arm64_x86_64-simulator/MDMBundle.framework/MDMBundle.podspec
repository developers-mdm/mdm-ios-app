Pod::Spec.new do |s|
  s.name                    = 'MDMBundle'
  s.version                 = '3.9.14'
  s.summary                 = 'Hands MDM'
  s.homepage                = 'https://hands.com.br/'

  s.author                  = { 'Name' => 'robson.moreira@hands.com.br' }
  s.license                 = { :type => 'Apache-2.0', :file => 'MDMBundle/LICENSE' }

  s.platform                = :ios
  s.source                  = { :http => 'https://nexus.hands.com.br/repository/maven-external/br/com/hands/mdm/libs/ios/mdm-bundle/' + s.version.to_s + '/mdm-bundle-' + s.version.to_s + '.zip' }

  s.ios.deployment_target   = '10.0'
  s.ios.vendored_frameworks = 'MDMBundle/MDMBundle.xcframework'

  s.subspec 'MDM' do |mdm|
      mdm.dependency 'MDMCore', s.version.to_s
      mdm.dependency 'MDMAppBehavior', s.version.to_s
      mdm.dependency 'MDMGeoBehavior', s.version.to_s
      mdm.dependency 'MDMNotification', s.version.to_s
  end

end
