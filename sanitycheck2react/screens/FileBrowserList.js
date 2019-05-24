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
  Alert,
  FlatList,
  Dimensions,
  TouchableOpacity
} from 'react-native';

import {createStackNavigator, createAppContainer} from 'react-navigation';
// import { List, ListItem } from "react-native-elements";
import { DocumentView, RNPdftron } from 'react-native-pdftron';

const styles = StyleSheet.create({

    MainContainer :{
        justifyContent: 'space-between',
        flex:1,
        //flexDirection: 'row',
        // margin: 5,
        alignItems: 'center',
        width: Dimensions.get('window').width,
        marginTop: (Platform.OS === 'ios') ? 20 : 0,
    },
    
    imageView: {
        height:250,
        width:"50%",
        //resizeMode: "cover",
        margin: 7,
        borderRadius : 7
    },
    
    textView: {
    
        width:'100%', 
        textAlignVertical:'center',
        textAlign: 'center',
        padding:10,
        color: '#000'
    }
    
  });

export default class FileBrowserList extends React.Component { 
    static navigationOptions = {
      title : 'Browse Files'
    };
  
    constructor (props) { 
      super (props); 
      const {navigate} = this.props.navigation;
      
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
                <TouchableOpacity onPress = {() => this._onPress(item)}>
                  <View style = {styles.MainContainer}>
                      <Image
                        source = {{ uri:"http://10.0.3.2:8080/" + item.split('.').slice(0, -1).join('.') + ".png"}}
                        style= {styles.imageView}/>
                      <Text style={styles.textView}>{item}</Text>
                  </View>
                </TouchableOpacity>
                }
              >
              </FlatList>
          </View>
      );
    }
  
    _onPress = (name) => {
      console.log(name);
      this.props.navigation.push('Viewer');
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
          parsedList = []
          var re = /(?:\.([^.]+))?$/;
          for(let index = 0; index < responseJson.length; index++){
            var fileName = responseJson[index];
            console.log(fileName);
            console.log(re.exec(fileName));
            if(re.exec(fileName)[1] == "pdf" || re.exec(fileName)[1] == "docx"){
              parsedList.push(fileName);
            }
          }
  
          this.setState({
            filelist: parsedList
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

  // export default FileBrowserList