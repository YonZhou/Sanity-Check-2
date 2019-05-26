import React, { Component } from 'react';
import {
  Platform,
  StyleSheet,
  Text,
  Image,
  View,
  PermissionsAndroid,
  BackHandler,
  NativeModules,
  Alert
} from 'react-native';

import {createStackNavigator, createAppContainer} from 'react-navigation';
// import { List, ListItem } from "react-native-elements";
import { DocumentView, RNPdftron } from 'react-native-pdftron';
import FileBrowserList from './screens/FileBrowserList';
import {Viewer as documentViewer} from './screens/viewer';


type Props = {};
console.disableYellowBox = true;
const MainNavigator = createStackNavigator({
  Home: {screen: FileBrowserList},
  Viewer: {screen: documentViewer}
},
{
  initialRouteName: "Home"
});

const App = createAppContainer(MainNavigator);
export default App;

