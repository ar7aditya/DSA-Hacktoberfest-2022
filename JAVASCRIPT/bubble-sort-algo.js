var slice = [ ].slice;
var elements = 15;
var array = Array( elements ).fill( 0 ).map( function (_, i) {
    return i + 1;
} ).sort( function() {
    return Math.floor( Math.random( ) * elements ) - Math.floor( Math.random() * elements );
} );
var sortedArray = slice.call(array).sort( function (a, b) {
    return a-b;
} );
var pattern = function( array, index ) {
    var block = '\u2588';
    var focus = '\u2593';
    var blur = '\u2591';
    var length = array.length;
    var height = Math.max.apply( null, array );
    var shape = Array( height + 1 ).fill( 0 ).map( function ( ) {
        return Array( length ).fill( blur );
    } );
    var i, j, k;
    for ( i = 0; i !== height; i ++ ) {
        for ( j = 0; j !== length; j ++ ) {
            if ( array [ j ] > i ) {
                k = height - i;
                shape [ k ][ j ] = j===index ? focus : block;
            }
        }
    }
    return '\n' + shape.map( function ( col ) {
        return col.join( blur );
    } ).join( '\n' ) + '\n\n' + Array( length * 2 ).join( '\u2594' );
};
var arrayCompareLite = function ( ) {
    var args = slice.call( arguments ).map( JSON.stringify.bind(JSON) );
    var isArrEqu = true;
    for ( var i = 0; i !== args.length; i ++ ) {
        isArrEqu = args [ 0 ] === args [ i ];
    }
    return isArrEqu;
};
var lastIndexDifferentElementLocalLite = function ( ) {
    var args = slice.call( arguments, 0, 2 );
    var len = args[ 0 ].length;
    var index = 0;
    for (var i = len - 1; i !== -1; -- i) {
        if (args[ 0 ][ i ] !== args[ 1 ][ i ]) {
            index = i;
            break;
        }
    }
    return index;
};
for (var index = 0, length = array.length; index < length && !arrayCompareLite( array, sortedArray ); index ++) {
    console.log( pattern( array, index ) );
    if ( index + 1 === length ) {
        index = -1;
        length = lastIndexDifferentElementLocalLite( array, sortedArray ) + 1;
    }
    if ( array [ index + 1 ] < array [ index ] ) {
        array.splice( index, 2, array [ index+1 ], array [ index ] );
    }
}
console.log( pattern( array, index ) );
console.log( pattern( array ) );