import React, { Component } from 'react';
import {
  Platform,
  StyleSheet,
  Text,
  View,
  PermissionsAndroid,
  BackHandler,
  NativeModules,
  Alert,
  FlatList
} from 'react-native';

// import { List, ListItem } from "react-native-elements";

import { DocumentView, RNPdftron } from 'react-native-pdftron';

  type Props = {};
  const styles = StyleSheet.create({
  
    MainContainer :{
    
        justifyContent: 'center',
        flex:1,
        margin: 5,
        marginTop: (Platform.OS === 'ios') ? 20 : 0,
    
    },
    
    imageView: {
    
        width: '50%',
        height: 100 ,
        margin: 7,
        borderRadius : 7
    
    },
    
    textView: {
    
        width:'50%', 
        textAlignVertical:'center',
        padding:10,
        color: '#000'
    
    }
    
    });

  export default class FileBrowserList extends Component { 

  constructor (props) { 
    super (props);  
    this.state = {
                  filelist: []
                  };
  } 

  render () { 
    console.log(this.state.filelist);
    return (
        <View style = {styles.MainContainer}>
            <FlatList
              data = {this.state.filelist}
              ItemSeparatorComponent = {this.FileListItemSeperator.FileListItemSeperator}
              renderItem = {({item}) =>
                <View style = {{flex:1, flexDirection:'row'}}>
                    {/* <Image source = {{ uri: item.flow}} /> */}
                    <Text style={styles.textView}>{item}</Text>
                </View>
            
              }
            >
            
            </FlatList>
        </View>
    );
  }

  FileListItemSeperator = () => {
    return (
        <View
        style={{
            height: .5,
            width: "100%",
            backgroundColor: "#000",
        }}
        />
    );
  }

  webcall = () => {
    return fetch("http://10.0.3.2:8080/getFiles")
      .then((response) => response.json())
      .then((responseJson) => {
        this.setState({
          filelist: responseJson
        }, function() {
          // In this block you can do something with new state.
        });
      })
      .catch((error) => {
        console.error(error);
      });
  }

  componentDidMount(){
      this.webcall();
  }
};